#include "test.h"

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n), back(n);
        for(auto i: connections){
            adj[i[0]].push_back(i[1]);
            back[i[1]].push_back(i[0]);
        }
        queue<int>q;
        q.push(0);
        vector<bool>visited(n);
        int ans = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            visited[front] = true;
            for(int outward: adj[front]){
                if(!visited[outward]){
                    q.push(outward);
                    ans++;
                }
            }
            for(int inward: back[front]){
                if(!visited[inward]){
                    q.push(inward);
                }
            }
        }
        return ans;
    }
};