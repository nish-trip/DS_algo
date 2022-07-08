#include "test.h"

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<32; i++){
            int zeroes = 0, ones = 0;
            for(int num: nums){
                if(num&(1<<i)){
                    ones++;
                }
                else{
                    zeroes++;
                }
            }
            ans+= (zeroes*ones);
        }
        return ans;
    }
};