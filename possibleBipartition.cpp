#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(vector<vector<int>>& adj,int N,int node,vector<int>& color)
    {
        stack<int> st;
        st.push(node);
        color[node] = 1;
        while(!st.empty())
        {
            int curr = st.top();
            st.pop();
            for(int ele: adj[curr])
            {
                if(color[ele]==color[curr]) //Odd-cycle
                    return false;
                if(color[ele]==-1)  //Unvisited node
                {
                    color[ele] = 1-color[curr];
                    st.push(ele);
                }
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> adj(N+1);
        for(auto i: dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> color(N+1,-1);
        for(int i=1;i<=N;++i)
            if(color[i]==-1)
                if(!dfs(adj,N,i,color))
                    return false;
        return true;
    }
};
