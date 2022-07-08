#include "test.h"

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();
        set<string>s;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    string str = "";
                    int count = 0;
                    dfs(grid, i, j, str, "", count);
                    s.insert(str);
                }
            }
        }
        return s.size();
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, string& str, string c, int count){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        str+= to_string(count);
        str+=c;
        count++;
        dfs(grid, i+1, j, str, "d",count);
        dfs(grid, i-1, j, str, "u",count);
        dfs(grid, i, j+1, str, "r",count);
        dfs(grid, i, j-1, str, "l",count);
    }
};