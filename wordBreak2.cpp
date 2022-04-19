#include "test.h"

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& dict) {
        vector<string>path;
        vector<vector<string>>paths;
        dfs(s, 0, path, paths, dict);
        vector<string>ans;
        for(auto vec: paths){
            string temp = "";
            for(string str: vec){
                temp += str;
                temp += " ";
            }
            temp.erase(temp.end()-1);
            ans.push_back(temp);
        }
        return ans;
    }
    
    void dfs(string s, int index, vector<string>& path, vector<vector<string>>& paths, vector<string>& dict){
        if(s.size() == index){
            paths.push_back(path);
        }
        for(int i=index; i<s.size(); i++){
            if(find(dict.begin(), dict.end(), s.substr(index, i-index+1)) != dict.end()){
                path.push_back(s.substr(index, i-index+1));
                dfs(s, i+1, path, paths, dict);
                path.pop_back();
            }
        }
    }
};