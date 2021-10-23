#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node
{
	int data;
	struct Node *next;
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
		vector<int>result;
		if(!root){
			return result;
		}
		unordered_map<int,int>hash;
		int maxCount = 0; 
		dfs(root, hash, maxCount);
		for(auto x: hash){
			if(x.second == maxCount){
				result.push_back(x.first);
			}
		}
		return result;
    }
	int dfs(TreeNode* root, unordered_map<int,int>& hash, int& maxCount){
		if(!root){
			return 0;
		}
		int sum = dfs(root->left, hash, maxCount)+dfs(root->right, hash, maxCount)+root->val;
		hash[sum]++;
		maxCount = max(maxCount,hash[sum]);
		return sum;
	}
};
