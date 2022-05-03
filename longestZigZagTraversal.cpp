#include "test.h"

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
    vector<int>dfs(TreeNode* root, int& ans){
        if(!root){
            return {-1, -1};
        }
        vector<int>left = dfs(root->left, ans);
        vector<int>right = dfs(root->right, ans);
        ans = max(ans, max(left[1], right[0])+1);
        return {left[1]+1, right[0]+1};
    }
};