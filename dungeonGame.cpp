#include "test.h"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // [[-2,-3,3],[-5,-10,1],[10,30,-5]]
        int m=dungeon.size(), n=dungeon[0].size();
        vector<vector<int>>dp(m, vector<int>(n));
        dp[m-1][n-1] = min(0, dungeon[m-1][n-1]);
        for(int i=n-2; i>=0; i--){
            dp[m-1][i] = dungeon[m-1][i] + dp[m-1][i+1];
            dp[m-1][i] = min(dp[m-1][i], 0);
        }
        for(int i=m-2; i>=0; i--){
            dp[i][n-1] = dungeon[i][n-1] + dp[i+1][n-1];
            dp[i][n-1] = min(dp[i][n-1], 0);
        }
        for(int i=m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                dp[i][j] = dungeon[i][j] +max(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = min(dp[i][j], 0);
            }
        }
        return abs(dp[0][0]) + 1;
    }
};