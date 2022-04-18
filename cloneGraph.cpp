#include "test.h"

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        unordered_map<Node*, Node*>hash;
        return dfs(node, hash);
    }
    
    Node* dfs(Node* node, unordered_map<Node*, Node*>& hash){
        if(hash.count(node)){
            return hash[node];
        }
        
        Node* newNode = new Node(node->val);
        hash[node] = newNode;
        for(Node* neighbour: node->neighbors){
            newNode->neighbors.push_back(dfs(neighbour, hash));
        }
        return newNode;
    }
};