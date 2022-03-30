#include "test.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		unordered_set<int>s;
		for(int num: nums){
			s.insert(num);
		}
		int ans = 1;
		for(int num: nums){
			if(s.count(num-1)){
				continue;
			}

			else if(!s.count(num-1) && s.count(num+1)){
				int cur = 1;
				//[100,4,200,1,3,2]
				while(s.count(++num)){
					cur++;
				}
				ans = max(ans, cur);
			}
		}
		return ans;
    }
};
