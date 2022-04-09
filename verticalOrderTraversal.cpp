#include "test.h"

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        map<int,vector<int>>hash;
        queue<pair<int,TreeNode*>>q;
        q.push({0, root});
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto front = q.front();
                q.pop();
                int line = front.first;
                TreeNode* node = front.second;
                hash[line].push_back(node->val);
                if(node->left){
                    q.push({line-1, node->left});
                }
                if(node->right){
                    q.push({line+1, node->right});
                }
            }
        }      
        for(auto i: hash){
            ans.push_back(i.second);
        }
        return ans;  
    }
};