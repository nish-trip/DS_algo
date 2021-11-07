#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root){
            return 0;
        }      
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode* root, int& ans){
        if(!root){
            return 0;
        }
        int left = dfs(root->left, ans);
        int leftVal = 0;
        if(root->left && root->val == root->left->val){
            leftVal = left+1;
        }
        int right = dfs(root->right, ans);
        int rightVal = 0;
        if(root->right && root->val == root->right->val){
            rightVal = right+1;
        }
        ans = max(ans, leftVal+rightVal);
        return max(leftVal, rightVal);
    }
};
