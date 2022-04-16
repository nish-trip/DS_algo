#include "test.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if(nodes.size() == 1){
            return nodes[0];
        }
        TreeNode* ans = NULL;
        for(int i=0; i<nodes.size(); i++){
            if(ans==NULL){
                ans = lca(root, nodes[0], nodes[1]);
            }
            else{
                ans = lca(root, nodes[i], ans);
            }
        }
        return ans;
    }
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if(!left) return right;
        if(!right) return left;
        return root;
    }
};