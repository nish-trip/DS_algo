#include "test.h"

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int>ans;    
        ans.push_back(root->val);
        if(!root->left && !root->right){
            return ans;
        }
        leftView(root, ans);
        bottomView(root, ans);
        rightView(root, ans);
        return ans;
    }

    void leftView(TreeNode* root, vector<int>& ans){
        TreeNode* cur = root->left;
        while(cur && !isLeaf(cur)){
            ans.push_back(cur->val);
            if(cur->left){
                cur = cur->left;
            }
            else{
                cur = cur->right;
            }
        }
    }

    void rightView(TreeNode* root, vector<int>& ans){
        vector<int>temp;
        TreeNode* cur = root->right;
        while(cur && !isLeaf(cur)){
            temp.push_back(cur->val);
            if(cur->right){
                cur = cur->right;
            }
            else{
                cur = cur->left;
            }
        }
        for(int i=temp.size()-1; i>=0; i--){
            ans.push_back(temp[i]);
        }
    }

    void bottomView(TreeNode* root, vector<int>& ans){
        if(!root) return;
        if(!root->left && !root->right){
            ans.push_back(root->val);
            return;
        }
        bottomView(root->left, ans);
        bottomView(root->right, ans);
    }

    bool isLeaf(TreeNode* root){
        if(!root->left && !root->right){
            return true;
        }
        return false;
    }
};