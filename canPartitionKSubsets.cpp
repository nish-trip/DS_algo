#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<bool>used(nums.size(), false);
        if(sum%k != 0) return false;
        return dfs(nums, k, 0, 0, sum/k, used);      
    }

    bool dfs(vector<int>& nums, int k, int start, int cur, int target, vector<bool>& used){
        if(k==1) return true;
        if(cur==target){
            return dfs(nums, k-1, 0, 0, target, used);
        }
        for(int i=start;i<nums.size(); i++){
            if(!used[i]){
                used[i] = true;
                if(dfs(nums, k, i+1, cur+nums[i], target, used)){
                    return true;
                }
                used[i] = false;
            }
        }
        return false;
    }
};
