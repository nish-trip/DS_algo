#include "test.h"

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        return dfs(root)[2];
    }
    
    // returns {min, max, largest}
    vector<int>dfs(TreeNode* root){
        if(!root){
            return {INT_MAX, INT_MIN, 0};
        }
        vector<int>left = dfs(root->left);
        vector<int>right = dfs(root->right);
        
        // if teh root is greater than the max in its left child and smaller than the min in its right child then its a BST
        if(root->val > left[1] && root->val < right[0]){
            return {min(left[0], root->val), max(right[1], root->val), 1+left[2]+right[2]};
        }

        // if it isnt a BST then we return vector such that its parent can also never be a BST and the largest subtree will be the largest val amongst its children
        return {INT_MIN, INT_MAX, max(left[2], right[2])};
    }
};