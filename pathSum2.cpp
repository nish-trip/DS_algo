#include "test.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>paths;
        vector<int>path;
        dfs(root, targetSum, path, paths);
        return paths;      
    }

    void dfs(TreeNode* root, int target, vector<int>& path, vector<vector<int>>& paths){
        if(!root){
            return;
        }
        path.push_back(root->val);
        if((root->val == target) && !root->left && !root->right){
            paths.push_back(path);
        }
        dfs(root->left, target-root->val, path, paths);
        dfs(root->right, target-root->val, path, paths);
        path.pop_back();
    }
};