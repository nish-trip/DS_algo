#include "test.h"

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        int goal = (sum+target)/2;
        if(target>sum || (sum+target)%2 || goal<0){
            return 0;
        }      
        int n = nums.size();
        int dp[n+1][goal+1];
        dp[0][0] = 1;
        for(int i=1; i<=goal; i++){
            dp[0][i] = 0;    
        }
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=goal; j++){
                if(j>=nums[i-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][goal];
    }
};