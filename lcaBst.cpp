#include "test.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* small = p->val < q->val ? p: q;
        TreeNode* big = p->val > q->val ? p: q;
        return helper(root, small, big);
    }

    TreeNode* helper(TreeNode* root, TreeNode* small, TreeNode* big){
        while(root->val < small->val || root->val > big->val) {
            while(root->val < small->val){
                root = root->right;
            }
            while(root->val > big->val){
                root = root->left;
            }
        }
        return root;
    }
};