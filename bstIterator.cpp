#include "test.h"

class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        fillStack(root);
    }

    void fillStack(TreeNode* root){
        TreeNode* temp = root;
        while(temp){
            st.push(temp);
            temp = temp->left;
        }
    }
    
    int next() {
        TreeNode* cur = st.top();
        st.pop();
        if(cur->right){
            fillStack(cur->right);
        }
        return cur->val;
    }
    
    bool hasNext() {
        return st.empty()? false: true;
    }
};