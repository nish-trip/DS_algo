#include "test.h"

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count =0, ans=0;
        int start=0;
        for(int end=0; end<nums.size(); end++){
            if(!nums[end]){ // if element is zero then increase the count
                count++;    // count strores the number of zeroes in the sliding window
            }
            while(count>k){     // while the number of zeroes is greater than k we shrink the window from the left
                if(!nums[start]){
                    count--;
                }
                start++;
            }
            ans = max(ans, end-start+1);
        }      
        return ans;
    }
};