#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& nums) {
        int ans = 0;
        vector<int>lmax(nums.size());
        vector<int>rmax(nums.size());
        for(int i=1; i<nums.size(); i++){
            lmax[i] = max(lmax[i-1], nums[i-1]);
        }
        for(int i=nums.size()-2; i>=0; i--){
            rmax[i] = max(rmax[i+1], nums[i+1]);
        }
        for(int i=1; i<nums.size()-1; i++){
            int level = min(lmax[i], rmax[i]);
            ans+= max(0, level-nums[i]);
        }      
        return ans;
    }
};
