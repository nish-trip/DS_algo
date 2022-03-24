#include "test.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n=matrix[0].size();
        int len = 0;
        vector<vector<int>>memo(m+1, vector<int>(n+1));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(matrix[i-1][j-1]){
                    memo[i][j] = 1+min(memo[i-1][j], min(memo[i-1][j-1], memo[i][j-1]));
                    len = max(len, memo[i][j]);
                }
            }
        }      
        return len*len;
    }
};