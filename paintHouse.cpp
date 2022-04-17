#include "test.h"

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n=costs.size();
        for(int i=1; i<n; i++){
            costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] += min(costs[i-1][1], costs[i-1][0]);
        }
        return *min_element(costs[n-1].begin(), costs[n-1].end());
    }
};