#include "test.h"

class Solution {
public:
    double maximumAverageSubtree(TreeNode* root) {
        double ans =0;
        dfs(root, ans);
        return ans;
    }
    
    vector<int> dfs(TreeNode* root, double& ans){  // {sum, count}
        if(!root){
            return {0,0};
        }
        vector<int> left = dfs(root->left, ans);
        vector<int> right = dfs(root->right, ans);
        int sum = root->val+left[0]+right[0];
        int count = 1+left[1]+right[1];
        ans = max(ans, 1.0*sum/count);
        return {sum, count};
    }
};