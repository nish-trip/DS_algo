#include "test.h"

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);
        string toStart = "", toDest = "";
        traverse(lca, startValue, toStart);
        traverse(lca, destValue, toDest);
        for(char& c : toStart){
            c = 'U';
        } 
        return toStart+toDest;
    }
    
    bool traverse(TreeNode* root, int val, string& str){
        if(!root) return false;
        if(root->val == val) return true;
        
        str.push_back('L');
        if(traverse(root->left, val, str)){
            return true;
        }
        str.pop_back();
        
        str.push_back('R');
        if(traverse(root->right, val, str)){
            return true;
        }
        str.pop_back();
        return false;
        
    }
    

    
    TreeNode* findLCA(TreeNode* root, int start, int dest){
        if(root == NULL){
            return NULL;
        }
        if(root->val == start || root->val == dest){
            return root;
        }
        TreeNode* left = findLCA(root->left, start, dest);
        TreeNode* right = findLCA(root->right, start, dest);
        if(!left) return right;
        if(!right) return left;
        return root;
    }
};