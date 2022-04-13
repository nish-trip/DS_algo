#include "test.h"

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        unordered_map<string,vector<TreeNode*>>hash;
        serialise(root, hash);
        for(auto i: hash){
            if(i.second.size()>1){
                ans.push_back(i.second[0]);
            }
        }
        return ans;
    }
    
    string serialise(TreeNode* root, unordered_map<string,vector<TreeNode*>>& hash){
        if(!root) return "#";
        string str = to_string(root->val)+" "+serialise(root->left, hash)+" "+serialise(root->right, hash)+" ";
        hash[str].push_back(root);
        return str;
    }
};