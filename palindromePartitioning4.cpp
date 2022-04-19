#include "test.h"

class Solution {
public:
    bool checkPartitioning(string s) {
        int n=s.size();
        // we make a dp table to check if s[i:j] is a palindrome, 
        vector<vector<bool>>dp(n, vector<bool>(n));
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(s[i] == s[j]){
                    dp[i][j] = ((i + 1 <= j - 1) ? dp[i + 1][j - 1] : true);
                }
            }
        }
        
        // iterate to find a scenario where s[0:i-1], s[i:j], s[j+1, n-1] are all palindromes. In this case we can spli the orignal string int 3 substrings
        for(int i=1; i<n-1; i++){
            for(int j=i; j<n-1; j++){
                if(dp[0][i-1] && dp[i][j] && dp[j+1][n-1]){
                    return true;
                }
            }
        }
        return false;
    }
};