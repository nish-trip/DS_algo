#include "test.h"

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n));
        vector<vector<int>>buildings(m, vector<int>(n));
        
        int numBuildings = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    numBuildings++;
                    bfs(grid, i, j, dp, buildings);
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if((grid[i][j] == 0) && (buildings[i][j] == numBuildings)){
                    ans = min(ans, dp[i][j]);
                }
            }
        }
        return ans==INT_MAX?-1: ans;
    }
    
    void bfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp, vector<vector<int>>& buildings){
        int m = grid.size(), n=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vector<pair<int,int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>>visited(m, vector<bool>(n));
        int steps = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto front = q.front();
                q.pop();
                for(auto dir: dirs){
                    int x = front.first+dir.first;
                    int y = front.second+dir.second;
                    if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || visited[x][y] || grid[x][y]) continue;
                    dp[x][y] += steps;
                    buildings[x][y]++;
                    visited[x][y] = true;
                    q.push({x,y});
                }
            }
            steps++;
        }
    }
};