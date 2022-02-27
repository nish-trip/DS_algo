#include "test.h"

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>memo(nums1.size()+1, vector<int>(nums2.size()+1));
        for(int i=1; i<=nums1.size(); i++){
            for(int j=1; j<=nums2.size(); j++){
                if(nums1[i-1] == nums2[j-1]){
                    memo[i][j] = 1+memo[i-1][j-1];
                }
                else{
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                }
            }
        }        
        return memo[nums1.size()][nums2.size()];
    }
};