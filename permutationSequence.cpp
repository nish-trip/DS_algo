#include "test.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums;
        for(int i=1; i<=n; i++){
            nums.push_back(i);
        }
        while(--k){
            nextPermutation(nums);
        }
        string str = "";
        for(int num: nums){
            str+= to_string(num);
        }
        return str;
    }

    void nextPermutation(vector<int>& nums){
        int i;
        for(i=nums.size()-2; i>=0; i--){
            if(nums[i+1]>nums[i]){
                break;
            }
        }
        reverse(nums.begin()+i+1, nums.end());
        if(i==-1){
            return;
        }
        auto itr = upper_bound(nums.begin()+i+1, nums.end(), nums[i]);
        swap(nums[i], *itr);
    }
};