#include "test.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //text1 = "abcde", text2 = "ace"
        int m = text1.size(), n=text2.size();
        vector<vector<int>>memo(m+1, vector<int>(n+1));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i-1] == text2[j-1]){
                    memo[i][j] = 1+memo[i-1][j-1];
                }
                else{
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                }
            }
        }      
        return memo[m][n];
    }
};