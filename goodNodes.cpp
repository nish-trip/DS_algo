#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }      
        int count = 0;
        dfs(root, INT_MIN, count);
        return count;
    }

    void dfs(TreeNode* root, int val, int& count){
        if(!root){
            return ;
        }
        if(root->val >= val){
            count++;
        }
        dfs(root->left, max(val, root->val), count);
        dfs(root->right, max(val, root->val), count);
    }
};
