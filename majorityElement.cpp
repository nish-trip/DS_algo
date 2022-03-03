#include "test.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int index = 0;
        int count =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[index] != nums[i]){
                count--;
                if(!count){
                    index = i;
                    count=1;
                }
            }
            else{
                count++;
            }
        }   
        return nums[index];
    }
};