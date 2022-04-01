#include "test.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum= accumulate(nums.begin(), nums.end(), 0);
        if(sum == x) return nums.size();
        int target = sum-x;
        // find the longes subarray whose sum is equal to target
        int len = 0, cur=0;
        unordered_map<int,int>hash;
        hash[0] = -1;
        bool flag = true;
        for(int i=0; i<nums.size(); i++){
            cur+= nums[i];
            if(hash.count(cur-target)){
                len = max(len, i-hash[cur-target]);
                flag = false;
            }
            if(!hash.count(cur)){
                hash[cur] = i;
            }
        }
        if(flag){
            return -1;
        }
        return nums.size()-len;
    }
};