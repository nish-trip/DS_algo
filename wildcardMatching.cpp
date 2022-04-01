#include "test.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>>memo(s.size()+1, vector<bool>(p.size()+1));
        memo[0][0] = true;
        for(int i=1; i<=p.size(); i++){
            // as long as the starting chars of the pattern are only *, the pattern can still match the string
            if(p[i-1] == '*'){
                memo[0][i] = true;
            }
            else{
                break;
            }
        }      
        
        for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=p.size(); j++){
                if(p[j-1] == '*'){
                    memo[i][j] = memo[i-1][j] || memo[i][j-1]; //   it matches so we check with the previous char of the string or if it doesnt match then we chech with previous of the pattern
                }
                else{
                    if(p[j-1] == '?' || p[j-1] == s[i-1]){
                        memo[i][j] = memo[i-1][j-1];
                    }
                }
            }
        }
        return memo[s.size()][p.size()];
    }
};