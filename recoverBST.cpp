#include "test.h"

class Solution {
public:
    TreeNode* prev;
    TreeNode* mid;
    TreeNode* first;
    TreeNode* last;
    
    void recoverTree(TreeNode* root) {
        first = last = prev = mid = NULL;
        inorder(root);
        if(first && last){
            swap(first->val, last->val);
        }
        else if(first && mid){
            swap(first->val, mid->val);
        }
    }
    
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        
        if(prev != NULL && root->val<prev->val){
            if(first == NULL){
                first = prev;
                mid = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        
        inorder(root->right);
    }
};