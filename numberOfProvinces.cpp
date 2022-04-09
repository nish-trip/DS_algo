#include "test.h"

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // [[1,1,0],[1,1,0],[0,0,1]]
        vector<bool>used(isConnected.size());
        int ans =0;
        for(int i=0; i<isConnected.size(); i++){
            if(!used[i]){
                ans++;
                dfs(isConnected, i, used);
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& isConnected, int num, vector<bool>& used){
        used[num] = true;
        for(int i=0; i<isConnected[num].size(); i++){
            if(!used[i] && isConnected[num][i]){
                dfs(isConnected, i, used);
            }
        }
    }
};