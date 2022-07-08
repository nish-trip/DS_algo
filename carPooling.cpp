#include "test.h"

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    
    struct compare{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[2]>b[2];
        }    
    };
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), cmp);
        int cur = 0;
        priority_queue<vector<int>, vector<vector<int>>, compare>pq;
        for(auto trip: trips){
            int pas = trip[0], start = trip[1], end = trip[2];
            while(!pq.empty() && pq.top()[2]<=start){
                cur-= pq.top()[0];
                pq.pop();
            }
            cur+= pas;
            if(cur>capacity){
                return false;
            }
            pq.push(trip);
        }
        return true;
    }
};