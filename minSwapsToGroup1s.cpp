#include "test.h"

class Solution {
public:
    int minSwaps(vector<int>& data) {
        // maintain a sliding window of size equal to the number of 1s. the min swaps will the minimum of the number of 0s in each of these windows
        int count = 0, start=0;
        for(int num: data){
            if(num){
                count++;
            }
        }
        int zerocount = 0;
        int ans = count;
        for(int end=0; end<data.size(); end++){
            if(!data[end]){
                zerocount++;
            }
            if(end>=count-1){
                ans = min(ans, zerocount);
                if(data[start++] == 0){
                    zerocount--;
                }
            }
        }
        return ans;
    }
};