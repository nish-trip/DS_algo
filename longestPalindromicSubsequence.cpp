#include "test.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>memo(s.size(), vector<int>(s.size()));
        for(int i=s.size()-1; i>=0; i--){
            memo[i][i] = 1;
            for(int j=i+1; j<s.size(); j++){
                if(s[i] == s[j]){
                    memo[i][j] = 2+memo[i+1][j-1];
                }
                else{
                    memo[i][j] = max(memo[i+1][j], memo[i][j-1]);
                }
            }
        }      
        return memo[0][s.size()-1];
    }
};