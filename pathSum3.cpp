#include "test.h"

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return dfs(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);      
    }

    int dfs(TreeNode* root, int target){
        if(!root){
            return 0;
        }
        int left = dfs(root->left, target-root->val);
        int right = dfs(root->right, target-root->val);
        return (root->val == target) + left+right;
    }
};