#include "test.h"


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size(),-1);
        unordered_map<int,int>hash;
        stack<int>st;
        for(int num: nums2){
            while(!st.empty() && num>st.top()){
                hash[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }      
        for(int i=0; i<nums1.size(); i++){
            if(hash.count(nums1[i])){
                ans[i] = hash[nums1[i]];
            }
        }
        return ans;
    }
};