#include "test.h"

class Solution {
public:
    queue<vector<int>>q;
    vector<vector<bool>>vis;
    
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();
        vis.resize(m, vector<bool>(n));
        bool found = false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j]){
                    dfs(grid, i, j);
                    found = true;
                    break;
                }
            }
            if(found){
                break;
            }
        }
        

        int steps = 0;
        vector<vector<int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int size = q.size();
            steps++;
            for(int i=0; i<size; i++){
                auto front = q.front();
                q.pop();
                for(auto dir: dirs){
                    int x = dir[0]+front[0];
                    int y = dir[1]+front[1];
                    if(x<0 || y<0 || x>=m || y>=n || vis[x][y]){
                        continue;
                    }
                    if(grid[x][y] == 1){
                        return steps-1;
                    }
                    vis[x][y] = true;
                    q.push({x,y});
                }
            }
            
        }
        return steps;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j] || grid[i][j] != 1){
            return;
        }
        vis[i][j] = true;
        grid[i][j] = 0;
        q.push({i,j});
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};