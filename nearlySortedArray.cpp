#include "test.h"

class Solution{
    public:
    struct compare{
        bool operator()(int a, int b){
            return a>b;
        }  
    };
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        priority_queue<int, vector<int>, compare>pq;
        int i;
        for(i=0; i<num; i++){
            if(!K) break;
            pq.push(arr[i]);
            K--;
        }
        vector<int>ans;
        for(; i<num; i++){
            pq.push(arr[i]);
            ans.push_back(pq.top());
            pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};