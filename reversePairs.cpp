#include "test.h"

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
    
    int mergeSort(vector<int>& nums, int start, int end){
        if(start>=end) return 0;
        int mid = start+(end-start)/2;
        int inversions = 0;
        inversions += mergeSort(nums, start, mid);
        inversions += mergeSort(nums, mid+1, end);
        inversions += mergeHalves(nums, start, end);
        return inversions;
    }
    
    int mergeHalves(vector<int>& nums, int start, int end){
        if(start>=end) return 0;
        vector<long long>buffer(end-start+1);
        long long mid = start+(end-start)/2;
        long long lp = start, rp = mid+1, i=0;
        int inversions = 0;
        
        while(lp<=mid && rp<=end){
            if((long long)nums[lp] > (long long) 2*nums[rp]){
                inversions += (mid-lp+1);
                rp++;
            }
            else{
                lp++;
            }
        }
        
        lp = start, rp = mid+1;
        while(lp<=mid && rp<=end){
            if(nums[lp] <= nums[rp]){
                buffer[i++] = nums[lp++];
            }
            // nums[lp] > nums[rp]
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
        for(int j=start; j<=end; j++){
            nums[j] = buffer[j-start];
        }
        return inversions;
    }
};