#include "test.h"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int firstmin = INT_MAX, secondmin = INT_MAX;
        int index = -1;
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0){
                    dp[i][j] = grid[i][j];
                }
                else{
                    if(j==index){
                        dp[i][j] = grid[i][j]+secondmin;
                    }
                    else{
                        dp[i][j] = grid[i][j]+firstmin;
                    }
                }
            }
            firstmin = INT_MAX, secondmin = INT_MAX;
            for(int j=0; j<n; j++){
                if(dp[i][j]<firstmin){
                    secondmin = firstmin;
                    firstmin = dp[i][j];
                    index = j;
                }
                else if(dp[i][j]<secondmin){
                    secondmin = dp[i][j];
                }
            }
        }
        return firstmin;
    }
};