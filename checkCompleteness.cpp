#include "test.h"

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool seenNull = false;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front= q.front();
            q.pop();
            if(front==NULL){
                seenNull = true;
            }
            else{
                if(seenNull){
                    return false;
                }
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};