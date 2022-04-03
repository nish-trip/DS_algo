#include "test.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int index = inorder.size()-1;
		unordered_map<int,int>hash;
		for(int i=0; i<inorder.size(); i++){
			hash[inorder[i]] = i;
		}
		return helper(inorder, postorder, index, 0, inorder.size()-1, hash);
    }

	TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& index, int start, int end, unordered_map<int,int>& hash){
		if(start>end){
			return NULL;
		}
		TreeNode* root= new TreeNode(postorder[index--]);
		int pos= hash[root->val];
        root->right = helper(inorder, postorder, index, pos+1, end, hash);
		root->left = helper(inorder, postorder, index, start, pos-1, hash);
		return root;
	}
};