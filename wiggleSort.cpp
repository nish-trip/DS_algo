#include "test.h"

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++){
            if(i%2 && nums[i]<nums[i-1]){
                swap(nums[i], nums[i-1]);
            }
            else if(i%2==0 && nums[i]>nums[i-1]){
                swap(nums[i], nums[i-1]);
            }
        }
    }
};