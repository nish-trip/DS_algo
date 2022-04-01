#include "test.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        unordered_map<int,int>hash;
        for(int i=0; i<inorder.size(); i++){
            hash[inorder[i]] = i;
        }      
        return helper(preorder, inorder, index, 0, preorder.size()-1, hash);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& index, int start, int end, unordered_map<int,int>hash){
        if(start>end) return NULL;
        TreeNode* root = new TreeNode(preorder[index++]);
        int inorderIdx = hash[root->val];
        root->left = helper(preorder, inorder, index, start, inorderIdx-1, hash);
        root->right = helper(preorder, inorder, index, inorderIdx+1, end, hash);
        return root;
    }
};