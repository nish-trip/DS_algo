#include "test.h"

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);      
    }

    int atMost(vector<int>& nums, int k){
        int count =0, ans =0;
        int start=0;
        for(int end=0; end<nums.size(); end++){
            if(nums[end]%2){
                count++;
            }
            while(count>k){
                if(nums[start]%2){
                    count--;
                }
                start++;
            }
            ans+= end-start+1;
        }
        return ans;
    }
};