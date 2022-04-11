#include "test.h"

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        // firstiter stores the max profit we can get if we can sell the stock only once and we sell it at the index
        vector<int>firstIter(n);
        int minSoFar = INT_MAX;
        int curProfit = 0;
        for(int i=0; i<n; i++){
            curProfit = max(curProfit, nums[i]-minSoFar);
            minSoFar = min(minSoFar, nums[i]);
            firstIter[i] = curProfit;
        }
        // seconditer stores the max profit we can get if we buy the stock at that index and sell it at any index affter that 
        vector<int>secondIter(n);
        int maxSoFar = 0;
        curProfit = 0;
        // maxSoFar-nums[i] gives the profit if we buy on that day and sell after that
        for(int i=n-1; i>=0; i--){
            curProfit = max(curProfit, maxSoFar-nums[i]);
            maxSoFar = max(maxSoFar, nums[i]);
            secondIter[i] = curProfit;
        }
        // "firstIter[max(0, i-1)] + secondIter[i]", corresponds to selling first time before i 
        // and buying and selling the second stock on or after i
        int ans =0;
        for(int i=0; i<n; i++){
            ans = max(ans, firstIter[max(0, i-1)] + secondIter[i]); // firstiter[-1] is 0 hence we used max()
        }
        return ans;
    }
};