#include "test.h"

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n=mat[0].size();
        vector<int>ans;
        if(!mat.size()){
            return ans;
        }
        int r=0, c=0;
        bool up = true;
        while(r<m && c<n){
            // going up
            if(up){
                while(r>0 && c<n-1){
                    ans.push_back(mat[r][c]);
                    r--;
                    c++;
                }
                ans.push_back(mat[r][c]);  
                if(c == n-1){
                    r++;
                }
                else{
                    c++;
                }
            }
            // going down
            else{
                while(r<m-1 && c>0){
                    ans.push_back(mat[r][c]);
                    r++;
                    c--;
                }   
                ans.push_back(mat[r][c]);
                if(r==m-1){
                    c++;
                }
                else{
                    r++;
                }
            }
            up = !up;
        }
        return ans;
    }
};