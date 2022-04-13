#include "test.h"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n==1){
            return *min_element(matrix[0].begin(), matrix[0].end());
        }
        vector<int>prev(n);
        prev = matrix[0];
        vector<int>cur(n);
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                cur[j] = min(prev[max(0,j-1)]+matrix[i][j], min(prev[j]+matrix[i][j], prev[min(n-1, j+1)]+matrix[i][j]));
            }
            prev = cur;
        }
        return *min_element(cur.begin(), cur.end());
    }
};