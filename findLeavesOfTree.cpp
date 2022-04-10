#include "test.h"

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>>ans;
        height(root, ans);
        return ans;
    }
    
    // returns the height of the current root
    int height(TreeNode* root, vector<vector<int>>& ans){
        if(!root) return -1;
        // curHeight is the height of the current root
        int curHeight = 1+max(height(root->left, ans), height(root->right, ans));
        // if there does not exist a vector corresponding to the current height, we create one and add it to the ans vector
        if(curHeight == ans.size()){
            ans.push_back(vector<int>());
        }
        // the curHeight corresponds to the index of the ans vector and the root's val needs to be inserted to the vector at that index
        ans[curHeight].push_back(root->val);
        return curHeight;
    }
};