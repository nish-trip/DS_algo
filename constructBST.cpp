#include "test.h"

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return helper(preorder, index, INT_MIN, INT_MAX);
    }
    
    TreeNode* helper(vector<int>& preorder, int& index, int minVal, int maxVal){
        if(index == preorder.size() || preorder[index]<minVal || preorder[index]>maxVal){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = helper(preorder, index, minVal, root->val);
        root->right = helper(preorder, index, root->val, maxVal);
        return root;
    }
};