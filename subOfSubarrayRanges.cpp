#include "test.h"

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int>minStack, maxStack;
        vector<long long>leftMin(n), rightMin(n);
        vector<long long>leftMax(n), rightMax(n);
        for(int i=0; i<n; i++){
            while(!minStack.empty() && nums[i]<=nums[minStack.top()]){
                minStack.pop();
            }
            leftMin[i] = minStack.empty()? i+1: i-minStack.top();
            minStack.push(i);
            
            while(!maxStack.empty() && nums[i]>=nums[maxStack.top()]){
                maxStack.pop();
            }
            leftMax[i] = maxStack.empty()? i+1: i-maxStack.top();
            maxStack.push(i);
        }
        
        while(!minStack.empty()){
            minStack.pop();
        }
        while(!maxStack.empty()){
            maxStack.pop();
        }
        
        for(int i=n-1; i>=0; i--){
            while(!minStack.empty() && nums[i]<nums[minStack.top()]){
                minStack.pop();
            }
            rightMin[i] = minStack.empty()? n-i: minStack.top()-i;
            minStack.push(i);
            
            while(!maxStack.empty() && nums[i]>nums[maxStack.top()]){
                maxStack.pop();
            }
            rightMax[i] = maxStack.empty()? n-i: maxStack.top()-i;
            maxStack.push(i);
        }
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += (leftMax[i]*rightMax[i] - leftMin[i]*rightMin[i])*nums[i] ;
        }
        return sum;
    }
};