#include "test.h"

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        vector<vector<int>>ans;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>>pac(rows, vector<bool>(cols));
        vector<vector<bool>>atl(rows, vector<bool>(cols));
        
        for(int i=0; i<rows; i++){
            dfs(grid, pac, i, 0, grid[i][0]);
            dfs(grid, atl, i, cols-1, grid[i][cols-1]);
        }
        for(int i=0; i<cols; i++){
            dfs(grid, pac, 0, i, grid[0][i]);
            dfs(grid, atl, rows-1, i, grid[rows-1][i]);
        }
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vec, int i, int j, int prev){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] < prev || vec[i][j] == true){
            return;
        }
        vec[i][j] = true;
        dfs(grid, vec, i+1, j, grid[i][j]);
        dfs(grid, vec, i-1, j, grid[i][j]);
        dfs(grid, vec, i, j+1, grid[i][j]);
        dfs(grid, vec, i, j-1, grid[i][j]);
    }
};