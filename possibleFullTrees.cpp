#include "test.h"

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>>hash;
        hash[0] = {};
        hash[1] = {new TreeNode()};
        return dfs(n, hash);
    }
    
    vector<TreeNode*> dfs(int n, unordered_map<int, vector<TreeNode*>>& hash){
        if(hash.find(n) != hash.end()){
            return hash[n];
        }
        vector<TreeNode*>ans;
        for(int l = 0; l<n; l++){
            int r = n-1-l;
            vector<TreeNode*> leftTrees = dfs(l, hash);
            vector<TreeNode*> rightTrees = dfs(r, hash);
            for(auto left: leftTrees){
                for(auto right: rightTrees){
                    ans.push_back(new TreeNode(0, left, right));
                }
            }
        }
        hash[n] = ans;
        return ans;
    }
};