#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.size()){
            return {};
        }
        vector<string>mapping{"","","abc","def","ghi", "jkl","mno","pqrs", "tuv","wxyz"};
        string str;
        vector<string>ans;
        dfs(digits, 0, str, ans, mapping);
        return ans;
    }

    void dfs(string digits, int index, string str, vector<string>& ans, vector<string>& map){
        if(digits.size() == str.size()){
            ans.push_back(str);
            return;
        }
        int cur = digits[index]-'0';
        string letters = map[cur];
        for(int i=0; i<letters.size(); i++){
            str.push_back(letters[i]);
            dfs(digits, index+1, str, ans, map);
            str.pop_back();
        }
    }
};
