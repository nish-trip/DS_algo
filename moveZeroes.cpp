#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // [0,1,0,3,12]
        int index = 0;
        for(int num: nums){
            if(num){
                nums[index++] = num;
            }
        }      
        for(;index<nums.size(); index++){
            nums[index] = 0;
        }
    }
};
