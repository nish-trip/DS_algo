#include "test.h"

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int s,e;
        int n = arr.size();
        bool sorted = true;
        for(e = n-1; e>0; e--){
            if(arr[e-1] > arr[e]){
                sorted = false;
                break;
            }
        }
        if(sorted){
            return 0;
        }
        int ans = e;
        for(s=0; s<e && (s==0|| arr[s-1] <= arr[s]) ; s++){
            while(e<n && arr[e]<arr[s]){
                e++;
            }
            ans = min(ans, e-s-1);
// length of array = e-s+1, but we have to exclude arr[s]&arr[e] since they are part of the valid subarrays 
//and we need to remove subarray b/w them
        }
        return ans;
    }
};