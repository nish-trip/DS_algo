#include "test.h"

class Solution {
public:
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxPath = 0, n = matrix.size(), m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                maxPath = max(maxPath, solve(matrix, i, j, -1,dp));            
            }
        }
        return maxPath;
    }
    int solve(vector<vector<int>>& mat, int i, int j, int prev, vector<vector<int>>& dp){
        // if it is out of bound or previous value is greater then we return
        if(i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] <= prev) return 0;
        // if dp is already computed tehn we return 
        if(dp[i][j]) return dp[i][j];
        return dp[i][j] = 1 + max({ solve(mat, i + 1, j, mat[i][j],dp),
                                    solve(mat, i - 1, j, mat[i][j],dp),
                                    solve(mat, i, j + 1, mat[i][j],dp),
                                    solve(mat, i, j - 1, mat[i][j],dp) });       
    }
};