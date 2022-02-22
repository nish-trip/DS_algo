#include "test.h"

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax=0, ansMax = INT_MIN, curMin = 0, ansMin = INT_MAX;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        bool neg = true; // check if array has only negative value
        for(int num: nums){
            if(num>0){
                neg = false;
            }
            curMax = max(curMax+num, num);
            ansMax = max(ansMax, curMax);
            curMin = min(num, num+curMin);
            ansMin = min(ansMin, curMin);
        }
        if(neg){
            return *max_element(nums.begin(), nums.end());
        }
        return max(ansMax, sum-ansMin);
    }
};