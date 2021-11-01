#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        for(int i=0; i<grid.size(); i++){
            if(target > grid[i][grid[0].size()-1]){
                continue;
            }
            return bs(grid[i], target);
        }
        return false;
    }

    bool bs(vector<int>& nums, int target){
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m] == target){
                return true;
            }
            if(target>nums[m]){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return false;
    }
};
