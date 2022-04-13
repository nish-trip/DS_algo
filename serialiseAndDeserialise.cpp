#include "test.h"

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        string str =  to_string(root->val)+' ';
        str+= serialize(root->left)+' ';
        str+= serialize(root->right)+' ';
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#"){
            return NULL;
        }
        stringstream s(data);
        return deserialize(s);
    }
    
    TreeNode* deserialize(stringstream& s){
        string word;
        s >> word;
        if(word == "#"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(word));
        root->left = deserialize(s);
        root->right = deserialize(s);
        return root;
    }
};