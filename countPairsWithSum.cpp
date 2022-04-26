#include "test.h"

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int>hash;
        int count =0;
        for(int i=0; i<n; i++){
            if(hash.count(k-arr[i])){
                count+= hash[k-arr[i]];
            }
            hash[arr[i]]++;
        }
        return count;
    }
};