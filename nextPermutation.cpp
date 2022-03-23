#include "test.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for(i=nums.size()-2; i>=0; i--){
            if(nums[i+1]>nums[i]){
                break;
            }
        }      
        reverse(nums.begin()+i+1, nums.end());
        if(i==-1){
            return;
        }
        auto itr = upper_bound(nums.begin()+i+1, nums.end(), nums[i]);
        swap(*itr, nums[i]);
    }
};