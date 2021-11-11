#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int ladder = nums[0], stairs = nums[0];
        int jump = 1;
        for(int i=1; i<nums.size(); i++){
            if(i==nums.size()-1){
                return jump;
            }
            if(i+nums[i] > ladder){
                ladder = nums[i]+i;
            }
            stairs--;
            if(stairs == 0){
                jump++;
                stairs = ladder-i;
            }
        }      
        return jump;
    }
};
