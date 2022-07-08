#include "test.h"

class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        unordered_map<string,vector<int>>hash;
        return solve(s, hash);
    }
    
    vector<int> solve(string str, unordered_map<string, vector<int>>& hash){
        if(hash.count(str)){
            return hash[str];
        }
        if(str.size() == 0) return {0};
        if(str.size() == 1 && isDigit(str[0])){
            return {str[0]};
        }
        
        vector<int>ans;
        for(int i=0; i<str.size(); i++){
            if(!isDigit(str[i])){
                vector<int>left = solve(str.substr(0,i), hash);
                vector<int>right = solve(str.substr(i+1), hash);
                for(int l: left){
                    for(int r: right){
                        if(str[i] == '+'){
                            ans.push_back(l+r);
                        }
                        if(str[i] == '-'){
                            ans.push_back(l-r);
                        }
                        if(str[i] == '*'){
                            ans.push_back(l*r);
                        }
                    }
                }
            }
        }
        hash[str] = ans;
        return ans;
    }
    
    bool isDigit(char c){
        return c-'0'>=0 && c-'0'<=9;
    }
};