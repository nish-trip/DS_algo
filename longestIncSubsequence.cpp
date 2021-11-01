#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		vector<int>memo(nums.size(),1);
		for(int i=0; i<nums.size(); i++){
			for(int j=0; j<i; j++){
				if(nums[i]>nums[j]){
					memo[i] = max(memo[i], memo[j]+1);
				}
			}
		}
		int val = *max_element(memo.begin(), memo.end());
		return val;
    }
};