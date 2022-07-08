#include "test.h"

class Solution {
public:
    int furthestBuilding(vector<int>& nums, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>>pq;
        int numBricks = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                int diff = nums[i]-nums[i-1];
                pq.push(diff);
                if(pq.size()>ladders){
                    numBricks += pq.top();
                    pq.pop();
                }
                if(numBricks > bricks){
                    return i-1;
                }
            }
        }
        return nums.size()-1;
    }
};