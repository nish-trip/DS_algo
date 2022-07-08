#include "test.h"

class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();
        deque<int>q;
        q.push_back(0);
        
        for(int i=1; i<n; i++){
            if(!q.empty() && i-q.front()>k){
                q.pop_front();
            }
            nums[i] += nums[q.front()];
            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        return nums[n-1];
    }
};