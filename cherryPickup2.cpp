#include "test.h"

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return dfs(0,0,grid[0].size()-1, grid, dp);
    }
    
    int dfs(int row, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(row>=grid.size() || col1<0 || col2<0 || col1>=grid[0].size() || col2>=grid[0].size()){
            return 0;
        }
        if(dp[row][col1][col2] != -1){
            return dp[row][col1][col2];
        }
        int maxVal = 0;
        for(int j1 = -1; j1<=1; j1++){
            for(int j2 = -1; j2<=1; j2++){
                int val = 0;
                if(col1 == col2){
                    val = grid[row][col1];
                }
                else{
                    val = grid[row][col1]+grid[row][col2];
                }
                val+= dfs(row+1, col1+j1, col2+j2, grid, dp);
                maxVal = max(maxVal, val);
            }
        }
        dp[row][col1][col2] = maxVal;
        return dp[row][col1][col2];
    }
};