#include "test.h"

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        ans[0] = 0;
        int offset = 1;
        int count=0;
        for(int i=1; i<=n; i++){
            ans[i] = 1+ans[i-offset];
            count++;
            if(count==offset){
                offset*=2;
                count = 0;
            }
        }
        return ans;
    }
};