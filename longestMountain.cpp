#include "test.h"

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=1; i<n; i++){
            int count = 1;
            bool flag = false;
            int j= i;
            while(j<n && arr[j]>arr[j-1]){
                j++;
                count++;
            }
            while(i!=j && j<n && arr[j]<arr[j-1]){
                j++;
                count++;
                flag = true;
            }
            
            if(flag && count>=3){
                ans = max(ans, count);
                j--;
            }
            i = j;
        }
        return ans;
    }
};