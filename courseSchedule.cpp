#include "test.h"

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<int>used(n);
        for(int i=0; i<n; i++){
            if(!used[i] && cycle(adj, used, i)){
                return {};
            }
        }
        stack<int>st;
        vector<bool>vis(n);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adj, vis, i, st);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

    void dfs(vector<vector<int>>& adj, vector<bool>& used, int i, stack<int>& st){
        used[i] = true;
        for(int num: adj[i]){
            if(!used[num]){
                dfs(adj, used, num, st);
            }
        }
        st.push(i);
    }

    bool cycle(vector<vector<int>>& adj, vector<int>& used, int i){
        if(used[i] == 1) return true;
        if(used[i] == 2) return false;
        used[i] = 1;
        for(int num: adj[i]){
            if(cycle(adj, used, num)){
                return true;
            }
        }
        used[i] = 2;
        return false;
    }
};