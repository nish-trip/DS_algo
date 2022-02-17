#include "test.h"

class Solution {
public:
    int orangesRotting(vector<vector<int> >& grid) {
        vector<vector<int> >dirs= {{1,0},{-1,0},{0,1},{0,-1}};
        int fresh = 0, ans  =-1;
        queue<pair<int,int> >q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int,int> front = q.front();
                q.pop();
                for(vector<int> dir: dirs){
                    int x = front.first + dir[0];
                    int y = front.second + dir[1];
                    if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y] != 1) continue;
                    grid[x][y] = 2;
                    fresh--; 
                    q.push(make_pair(x,y));
                }
            }
            ans++;
        }
        if(fresh) return -1;
        if(ans ==-1) return 0;
        return ans;
    }
};