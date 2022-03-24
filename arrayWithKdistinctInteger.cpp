#include "test.h"
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k)-atMost(nums, k-1);      
    }

    int atMost(vector<int>& nums, int k){
        unordered_map<int,int>hash;
        int start=0, ans=0;
        for(int end=0; end<nums.size(); end++){
            hash[nums[end]]++;
            while(hash.size()>k){
                hash[nums[start]]--;
                if(hash[nums[start]] == 0){
                    hash.erase(nums[start]);
                }
                start++;
            }
            ans+= end-start+1;
        }
        return ans;
    }
};