#include "test.h"

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int,int>hash;
        hash[0] = 1;
        return dfs(root, targetSum, 0, hash);
    }
    
    int dfs(TreeNode* root, int target, long sum, unordered_map<int,int>& hash){
        if(!root) return 0;
        sum+= root->val;
        int numPathsToCurr = 0;
        if(hash.count(sum-target)){
            numPathsToCurr+= hash[sum-target];
        }
        
        hash[sum]++;
        int numPaths = numPathsToCurr + dfs(root->left, target, sum, hash) + dfs(root->right, target, sum, hash);
        hash[sum]--;
        
        return numPaths;
    }
};