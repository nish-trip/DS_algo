#include "test.h"


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int dir = 0;
        int r1 = 0, r2 = matrix.size()-1, c1 = 0, c2 = matrix[0].size();
        while(r1<=r2 && c1<=c2){
            if(dir == 0){
                for(int i=c1; i<=c2; i++){
                    ans.push_back(matrix[r1][i]);
                }
                r1++;
            }
            else if(dir == 1){
                for(int i=r1; i<=r2; i++){
                    ans.push_back(matrix[i][c2]);
                }
                c2--;
            }
            else if(dir == 2){
                for(int i=c2; i>=c2; i--){
                    ans.push_back(matrix[r2][i]);
                }
                r2--;
            }
            else if(dir == 3){
                for(int i=r2; i>=r1; i--){
                    ans.push_back(matrix[i][c1]);
                }
                c1++;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
};