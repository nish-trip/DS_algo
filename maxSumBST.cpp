#include "test.h"

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
    // {min, max, maxSum}
    vector<int> dfs(TreeNode* root, int& ans){
        if(!root){
            return {INT_MAX, INT_MIN, 0};
        }
        
        vector<int>left = dfs(root->left, ans);
        vector<int>right = dfs(root->right, ans);
        // if it is a BST
        if(root->val > left[1] && root->val < right[0]){
            int sum = root->val+left[2]+right[2];
            ans = max(ans, sum);
            return {min(left[0], root->val), max(right[1], root->val), sum};
        }
        // if it isnt a BST then we return a vector such that its parent can never be BST
        return {INT_MIN, INT_MAX, 0};
    }
};