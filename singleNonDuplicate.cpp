#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r= nums.size()-1;
        int m;
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[r] != nums[r-1]){
            return nums[r];
        }
        while(l<=r){
            m = l+(r-l)/2;
            if(nums[m] != nums[m+1] && nums[m] != nums[m-1]){
                return nums[m];
            }
            if((!(m%2) && nums[m] == nums[m+1]) || (m%2) && nums[m] == nums[m-1]){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return -1;
    }
};


