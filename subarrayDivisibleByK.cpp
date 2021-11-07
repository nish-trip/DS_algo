#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        hash[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            sum+= nums[i];
            sum%= k;
            if(sum<0){
                sum+= k;
            }
            if(hash.count(sum)){
                ans+= hash[sum];
            }
            hash[sum]++;
        }      
        return ans;
    }
};
