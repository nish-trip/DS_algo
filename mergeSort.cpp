#include "test.h"


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;      
    }

    void mergesort(vector<int>& nums, int start, int end){
        if(start>=end) return;
        int mid = start+(end-start)/2;
        mergesort(nums, start, mid);
        mergesort(nums, mid+1, end);
        mergeHalves(nums, start, end);
    }

    void mergeHalves(vector<int>& nums, int start, int end){
        vector<int>buffer(end-start+1);
        int mid = start+(end-start)/2;
        int lp=start, rp=mid+1, i=0;
        while(lp<=mid && rp<=end){
            if(nums[lp]<nums[rp]){
                buffer[i++] = nums[lp++];
            }
            else{
                buffer[i++] = nums[rp++];
            }
        }
        while(lp<=mid){
            buffer[i++] = nums[lp++];
        }
        while(rp<=end){
            buffer[i++] = nums[rp++];
        }
        for(int i=start; i<=end; i++){
            nums[i] = buffer[i-start]; 
        }
    }
};