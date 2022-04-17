#include "test.h"

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int> values(n), dp(n);
        for(int num: nums){
            values[num] += num;
        }
        dp[0] = 0;
        dp[1] = values[1];
        for(int i=2; i<n; i++){
            dp[i] = max(values[i]+dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
};