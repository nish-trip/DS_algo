#include "test.h"

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>>q;
        int m=rooms.size(), n=rooms[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(rooms[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int i = front.first, j=front.second;
            for(auto dir: dirs){
                int x = i+dir.first, y= j+dir.second;
                if(x<0||y<0||x>=m||y>=n||rooms[x][y]<INT_MAX){
                    continue;
                }
                rooms[x][y] = 1+rooms[i][j];
                q.push({x,y});
            }
        }
    }
};