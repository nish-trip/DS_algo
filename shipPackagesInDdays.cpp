#include "test.h"

class Solution {
public:
    int shipWithinDays(vector<int>& nums, int days) {
        // each package need to be shifted as a whole
        // the least weight cant be lesser than the weight of the heaviest package coz otherwie this package never gets shipped
        // the best case would be if all the packages are shipped at once, so r=totalsum
        int l=*max_element(nums.begin(), nums.end()), r= accumulate(nums.begin(), nums.end(), 0);
        int ans = r;
        while(l<=r){
            int m=l+(r-l)/2;
        // cur_days will count the number of days it will take to ship if the weight caacity == m
            int cur_days = 0;
            int i=0;
            while(i<nums.size()){
                int temp_capacity = 0;
    // while the current capacity is less than m we continue adding more packages
                while(i<nums.size() && temp_capacity<=m){
                    temp_capacity+= nums[i];
                    if(temp_capacity > m){
                        break;
                    }
    // when the sum of packages crosses the capacity we break and increment the number of days, capcity is set to 0 
                    i++;
                }
                cur_days++;
                temp_capacity = 0;
            }
    // if it takes less than the required days then we search the left part
            if(cur_days<=days){
                ans = m;
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return ans;
    }
};