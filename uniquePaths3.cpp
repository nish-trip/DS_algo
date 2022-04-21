#include "test.h"

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x,y;
        int ans=0, empty = 0;
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    empty++;
                }
                if(grid[i][j] == 1){
                    empty++;
                    x=i;
                    y=j;
                }
            }
        }
        dfs(grid, x, y, empty, ans);
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int empty, int& ans){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] < 0){
            return;
        }
        if(grid[i][j] == 2){
            if(empty==0){
                ans++;
            }
            return;
        }
        grid[i][j] = -2;
        empty--;
        
        dfs(grid, i+1, j, empty, ans);
        dfs(grid, i-1, j, empty, ans);
        dfs(grid, i, j+1, empty, ans);
        dfs(grid, i, j-1, empty, ans);
        
        empty++;
        grid[i][j] = 0;
    }
};