#include "test.h"

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int>ans(2);// {withRoot, withoutRoot}
        ans = helper(root);
        return max(ans[0], ans[1]);
    }
    
    vector<int> helper(TreeNode* root){
        if(!root) return {0,0};
        vector<int>left = helper(root->left);
        vector<int>right = helper(root->right);
        vector<int>ans(2);
        ans[0] = root->val + left[1] + right[1]; // with current root so we include without leftchild and rightchild root
        ans[1] = max(left[0], left[1]) + max(right[0], right[1]); // without current root so we take sum of the max values we can get from the left and right child
        return ans;
    }
};