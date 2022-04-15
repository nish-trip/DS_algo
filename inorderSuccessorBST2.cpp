#include "test.h"

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node* iter = node;
        if(iter->right != NULL){
            iter = iter->right;
            while(iter->left){
                iter = iter->left;
            }
            return iter;
        }
        else{
            while(iter->parent && iter->parent->right == iter){
                iter = iter->parent;
            }
        }
        return iter->parent;
    }
};