#include "test.h"

class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        if(!root) return 0;
        int ans =0;
        dfs(root, ans);
        return ans;
    }
    
    // return if the condition holds till that root node
    bool dfs(TreeNode* root, int& ans){
        if(!root) return true;  // if root is NULL then teh condition holds
        bool leftDfs = dfs(root->left, ans);
        bool rightDfs = dfs(root->right, ans);
        // if the condition doesnt hold for either of its child tehn it can not hold for the current root
        if(!leftDfs || !rightDfs){
            return false;
        }
        // if the current value is not equal to its left or right child's value then return false
        if(root->left && root->val != root->left->val){
            return false;
        }
        if(root->right && root->val != root->right->val){
            return false;
        }
        // the condition holds till the current node so we increment ans and return true
        ans++;
        return true;
    }
};