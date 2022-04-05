#include "test.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }      
        int left = height(root->left);
        int right = height(root->right);
        return max(left+right, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }

    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return 1+max(left, right);
    }
};