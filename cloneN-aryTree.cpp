#include "test.h"

class Solution {
public:
    Node* cloneTree(Node* root) {
        if(!root){
            return NULL;
        }
        return dfs(root);
    }
    
    Node* dfs(Node* root){
        Node* node = new Node(root->val);
        for(Node* child: root->children){
            node->children.push_back(dfs(child));
        }
        return node;
    }
};