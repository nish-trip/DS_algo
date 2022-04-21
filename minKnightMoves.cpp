#include "test.h"

class Solution {
public:
    int hash(int x, int y){
        // instead of 1000 we couldve used any value >300
        return x*1000+y;    
    }
    
    int minKnightMoves(int x, int y) {
        vector<pair<int,int>>dirs = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        x = abs(x), y=abs(y) ;
        queue<pair<int,int>>q;
        q.push({0,0});
        unordered_set<int>visited;
        visited.insert(hash(0,0));
        int ans =0;
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto front = q.front();
                q.pop();
                int row = front.first;
                int col = front.second;
                if(row==x && col==y){
                    return ans;
                }
                for(auto dir: dirs){
                    int newRow = row+dir.first;
                    int newCol = col+dir.second;
                    if(!visited.count(hash(newRow, newCol)) && newRow>=-1 && newCol>=-1){
                        q.push({newRow, newCol});
                        visited.insert(hash(newRow, newCol));
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};