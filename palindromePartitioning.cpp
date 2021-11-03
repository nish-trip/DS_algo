#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>paths;
        vector<string>path;
        dfs(s, 0, path, paths);
        return paths;      
    }

    void dfs(string s, int start, vector<string>& path, vector<vector<string>>& paths){
        if(start == s.size()){
            paths.push_back(path);
        }
        else{
            for(int i=start; i<s.size(); i++){
                if(pal(s, start, i)){
                    path.push_back(s.substr(start, i-start+1));
                    dfs(s, i+1, path, paths);
                    path.pop_back();
                }
            }
        }
    }

    bool pal(string s, int b, int e){
        while(b<=e){
            if(s[b++] != s[e--]){
                return false;
            }
        }
        return true;
    }
};
