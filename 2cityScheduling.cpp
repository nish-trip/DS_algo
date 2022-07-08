#include "test.h"

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>>vec;
        for(auto i: costs){
            vec.push_back({i[1]-i[0], i[0], i[1]});
        }
        sort(vec.begin(), vec.end());
        int ans = 0;
        for(int i=0; i<n; i++){
            if(i<n/2){
                ans+= vec[i][2];
            }
            else{
                ans+= vec[i][1];
            }
        }
        return ans;
    }
};