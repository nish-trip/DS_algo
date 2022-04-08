#include "test.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum = target>=0? INT_MAX: INT_MIN; // or take any three elements randomly
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int start = i+1, end=nums.size()-1;
            while(start<end){
                int sum = nums[i]+nums[start]+nums[end];
                if(abs(sum-target) < abs(closestSum-target)){
                    closestSum = sum;
                }
                if(sum<target){
                    while(start<end && nums[start] == nums[start+1]){
                        start++;
                    }
                    start++;
                }
                else if(sum>target){
                    while(start<end && nums[end] == nums[end-1]){
                        end--;
                    }
                    end--;
                }
                else{
                    return sum;
                }
            }
        }    
        return closestSum;  
    }
};