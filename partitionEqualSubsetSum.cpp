#include "test.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0); 
        if(sum==0){
            return true;
        }
        if(sum%2){
            return false;
        }
        int target = sum/2;
        int n = nums.size();
        vector<vector<bool>>memo(n+1, vector<bool>(target+1, false));
        for(int i=0; i<=n; i++){
            memo[i][0] = true;
        }
        for(int i=1; i<=target; i++){
            memo[0][i] = false;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
                memo[i][j] = memo[i-1][j];
                if(j>=nums[i-1]){
                    memo[i][j] = (memo[i][j] || memo[i-1][j-nums[i-1]]);
                }
            }
        }
        return memo[n][target];
    }
};
