#include "test.h"

class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size() == 1) return 0;
        unordered_map<int,vector<int>>hash;
        for(int i=0; i<arr.size(); i++){
            hash[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        int steps = 0, n=arr.size();
        while(!q.empty()){
            steps++;
            int size = q.size();
            for(int i=0; i<size; i++){
                int front = q.front();
                q.pop();
                
                if(front-1>=0 && hash.count(arr[front-1])){
                    q.push(front-1);
                }
                
                if(front+1<n && hash.count(arr[front+1])){
                    if(front+1 == n-1){
                        return steps;
                    }
                    q.push(front+1);
                }
                
                int val = arr[front];
                if(hash.count(val)){
                    for(int num: hash[val]){
                        if(num != front){
                            if(num == n-1){
                                return steps;
                            }
                            q.push(num);
                        }
                    }
                    hash.erase(val);   
                }
            }
        }
        return steps;
    }
};