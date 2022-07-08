#include "test.h"

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char,int>hash;
        for(char c: s){
            hash[c]++;
        }
        int odd = 0;
        char c;
        for(auto i: hash){
            if(i.second%2){
                odd++;
                c = i.first;
            }
        }
        vector<string>ans;
        if(odd>1){
            return ans;
        }
        string str = "";
        if(odd){
            str.push_back(c);
        }
        dfs(hash, str, ans, s.size());
        return ans;
    }
    
    void dfs(unordered_map<char,int>& hash, string str, vector<string>& ans, int n){
        if(str.size() == n){
            ans.push_back(str);
            return;
        }
        for(auto i: hash){
            if(i.second>=2){
                hash[i.first] -=2;
                dfs(hash, i.first+str+i.first, ans, n);
                hash[i.first] +=2;
            }
        }
    }
};