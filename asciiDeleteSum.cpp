#include "test.h"

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n=s2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = (int)s1[i-1] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int sum = 0;
        for(char c: s1){
            sum+= (int)c;
        }
        for(char c: s2){
            sum+= (int)c;
        }
        return sum - (2*dp[m][n]);
    }
};