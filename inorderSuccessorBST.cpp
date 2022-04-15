#include "test.h"

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = NULL;
        while(root){
            if(root->val > p->val){
                ans = root;
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return ans;
    }
};