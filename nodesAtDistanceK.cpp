#include "test.h"

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent;
        markParent(root, parent);
        queue<TreeNode*>q;
        q.push(target);
        set<TreeNode*>visited;
        visited.insert(target);
        int level = 0;
        while(!q.empty()){
            if(level++ == k){
                break;
            }
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left && !visited.count(front->left)){
                    visited.insert(front->left);
                    q.push(front->left);
                }
                if(front->right && !visited.count(front->right)){
                    visited.insert(front->right);
                    q.push(front->right);
                }
                if(parent[front] && !visited.count(parent[front])){
                    visited.insert(parent[front]);
                    q.push(parent[front]);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
    
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left){
                    parent[front->left] = front;
                    q.push(front->left);
                }
                if(front->right){
                    parent[front->right] = front;
                    q.push(front->right);
                }
            }
        }
    }
};