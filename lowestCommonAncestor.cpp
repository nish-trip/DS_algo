#include "test.h"

class Solution {
public:
    bool pExists, qExists;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pExists = false;
        qExists = false;
        TreeNode* ans = lca(root, p, q);
        if(!pExists || !qExists){
            return NULL;
        }
        return ans;
    }
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if(root==p){
            pExists = true;
            return root;
        }
        if(root==q){
            qExists = true;
            return root;
        }       
        if(!left){
            return right;
        }
        if(!right){
            return left;
        }
        return root;
    }
};