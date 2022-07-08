#include "test.h"

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minv = INT_MAX, maxv = INT_MIN;
        int n = nums.size(),i = 1;
        bool sorted = true;
        // find the smallest number in the unsorted array
        for(; i<n; i++){
            if(nums[i]<nums[i-1]){
                minv = min(minv, nums[i]);
                sorted = false;
            }
        }
        if(sorted){
            return 0;
        }
        // find the largest number in the unsorted array
        for(i = n-2; i>=0; i--){
            if(nums[i]>nums[i+1]){
                maxv = max(maxv, nums[i]);
            }
        }
        int left = 0, right = n-1;
        // the first number bigger than the smallest number in unsorted array forms the left edge of the unsorted subarray
        for(i=0; i<n; i++){
            if(nums[i]>minv){
                left = i;
                break;
            }
        }

        // the first number smaller than the biggest number in unsorted array forms the right edge of the unsorted subarray
        for(i = n-1; i>=0; i--){
            if(nums[i] < maxv){
                right = i;
                break;
            }
        }
        return right-left+1;
    }
};