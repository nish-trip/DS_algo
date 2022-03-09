#include "test.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size());
        vector<int>nge(nums2.size(),-1);
        stack<int>st;
        for(int i=0; i<nums2.size(); i++){
            while(!st.empty() && nums2[i]>nums2[st.top()]){
                int idx = st.top();
                st.pop();
                nge[idx] = nums2[i];
            }
            st.push(i);
        }      
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums2[j] == nums1[i]){
                    ans[i] = nge[j];
                    break;
                }
            }
        }
        return ans;
    }
};