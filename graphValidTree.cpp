#include "test.h"

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // check if it is connected and doesnt contain cycles
        vector<vector<int>>adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // used to detect cycle
        vector<int>color(n,-1);
        int count = 0;// keeps track of the number of components;
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                count++;
                if(cycle(adj, i, color, -1)){
                    return false;
                }
            }
        }
        return count == 1;
    }
    
    bool cycle(vector<vector<int>>& adj, int i, vector<int>& color, int prev){
        if(color[i] == 1) return true;
        if(color[i] == 2) return false;
        color[i] = 1;
        for(int num: adj[i]){
            if(num!=prev && cycle(adj, num, color, i)){
                return true;
            }
        }
        color[i] = 2;
        return false;
    }
};