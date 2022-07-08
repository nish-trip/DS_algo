#include "test.h"

class Solution {
public:
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        map<int,int>hash;
        // hash[end] = profit
        hash[0] = 0;
        vector<vector<int>>jobs;
        // {end, start, profit}
        int n = start.size();
        for(int i=0; i<n; i++){
            jobs.push_back({end[i], start[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        
        for(int i=0; i<n; i++){
            int cur = jobs[i][2] + prev(hash.upper_bound(jobs[i][1]))->second;
            if(cur > hash.rbegin()->second){
                hash[jobs[i][0]] = cur;
            }
        }
        return hash.rbegin()->second;
    }
};