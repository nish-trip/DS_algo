#include "test.h"

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int mod = 1e9+7;
        if(k==1){
            return maxSum(arr)%mod;
        }
        
        long long sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum>=0){
            vector<int>temp(arr.begin(), arr.end());
            for(int num: temp){
                arr.push_back(num);
            }
            return (maxSum(arr) + sum*(k-2))%mod;
        }
            vector<int>temp(arr.begin(), arr.end());
            for(int num: temp){
                arr.push_back(num);
            }
            return maxSum(arr)%mod;
    }
    
    int maxSum(vector<int>& arr){
        int ans = 0, sum = 0;
        for(int num: arr){
            sum = max(sum+num, num);
            ans = max(ans, sum);
        }
        return ans;
    }
};