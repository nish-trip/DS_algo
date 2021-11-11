#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur = 0;
        for(int i=0; i<nums.size(); i++){
            if(i>cur){
                return false;
            }
            cur = max(cur, i+nums[i]);
        }      
        return true;
    }
};
