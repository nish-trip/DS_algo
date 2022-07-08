#include "test.h"

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int cur = 0;
        dfs(root, cur);
        return root;
    }
    
    void dfs(TreeNode* root, int& cur){
        if(!root) return;
        dfs(root->right, cur);
        cur+= root->val;
        root->val = cur;
        dfs(root->left, cur);
    }
};