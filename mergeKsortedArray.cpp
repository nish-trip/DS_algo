#include "test.h"

class Solution
{
    public:
    
    struct compare{
        bool operator()(vector<int>a, vector<int>b){
            return a[0]>b[0];
        }
    };
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<vector<int>, vector<vector<int>>, compare>pq;
        for(int i=0; i<arr.size(); i++){
            if(arr[i].size()){
                pq.push({arr[i][0], i, 0});
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            auto vec = pq.top();
            pq.pop();
            int val = vec[0];
            int row= vec[1];
            int col = vec[2];
            ans.push_back(val);
            if(col+1< arr[row].size()){
                pq.push({arr[row][col+1], row, col+1});
            }
        }
        return ans;
    }
};