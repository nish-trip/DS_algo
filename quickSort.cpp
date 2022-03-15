#include "test.h"

#include "test.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;      
    }

    void quickSort(vector<int>& nums, int start, int end){
        if(start>=end) return;
        int pivot = partition(nums, start, end);
        quickSort(nums, start, pivot-1);
        quickSort(nums, pivot+1, end);
    }

    int partition(vector<int>& nums, int start, int end){
        int p = end, i=start-1;
        for(int j=start; j<p; j++){
            if(nums[j]<nums[p]){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[p]);
        return i+1;
    }
};