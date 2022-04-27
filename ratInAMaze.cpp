#include "test.h"

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &grid, int n) {
        // Your code goes here
        vector<string>ans;
        string str = "";
        dfs(grid, str, 0, 0, ans);
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, string& str, int i, int j, vector<string>& ans){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]<=0){
            return;
        }
        if(i==grid.size()-1 && j==grid.size()-1){
            ans.push_back(str);
            return;
        }
        grid[i][j] = -1;
        
        str+="D";
        dfs(grid, str, i+1, j, ans);
        str.pop_back();
        str+="L";
        dfs(grid, str, i, j-1, ans);
        str.pop_back();
        str+="R";
        dfs(grid, str, i, j+1, ans);
        str.pop_back();
        str+="U";
        dfs(grid, str, i-1, j, ans);
        str.pop_back();
        
        grid[i][j] = 1;
    }
};