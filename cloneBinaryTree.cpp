#include "test.h"

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*>hash;
        hash[NULL] = NULL;
        dfs(root, hash);
        dfsConnect(root, hash);
        return hash[root];
    }
    
    void dfsConnect(Node* root, unordered_map<Node*, NodeCopy*>& hash){
        if(!root) return;
        NodeCopy* node = hash[root];
        node->left = hash[root->left];
        node->right = hash[root->right];
        node->random = hash[root->random];
        dfsConnect(root->left, hash);
        dfsConnect(root->right, hash);
    }
    
    void dfs(Node* root, unordered_map<Node*, NodeCopy*>& hash){
        if(!root) return;
        NodeCopy* node = new NodeCopy(root->val);
        hash[root] = node;
        dfs(root->left, hash);
        dfs(root->right, hash);
    }
};