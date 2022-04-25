#include "test.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        // if longest common subsequence is not t, return 0
        // find the count of such subsequences
        unsigned int m=s.size(), n=t.size();
        vector<vector<unsigned int>>dp(m+1, vector<unsigned int>(n+1));
        for(unsigned int i=0; i<=m; i++){
            dp[i][0] = 1;
        }
        for(unsigned int i=1; i<=m; i++){
            for(unsigned int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[m][n];
    }
};