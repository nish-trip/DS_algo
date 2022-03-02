#include "test.h"

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(!n){
            return {};
        }      
        return helper(1,n);
    }

    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*>res;
        if(start>end){
            res.push_back(NULL);
            return res;
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode*>left = helper(start, i-1);
            vector<TreeNode*>right = helper(i+1, end);
            for(auto leftTree: left){
                for(auto rightTree: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};