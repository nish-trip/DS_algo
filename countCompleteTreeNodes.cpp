#include "test.h"

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int left = leftHeight(root->left);
        int right = rightHeight(root->right);
        if(left == right){
            int height = left+1;
            return (1<<height)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    
    int leftHeight(TreeNode* root){
        if(!root) return 0;
        TreeNode* cur = root;
        int height = 0;
        while(cur){
            height++;
            cur = cur->left;
        }
        return height;
    }
    
    int rightHeight(TreeNode* root){
        if(!root) return 0;
        TreeNode* cur = root;
        int height = 0;
        while(cur){
            height++;
            cur = cur->right;
        }
        return height;
    }
};