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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> ans;
		string str = "";
		dfs(ans, str, 0,0, n);
		return ans;
    }

	void dfs(vector<string>& ans, string str, int open, int close, int max){
		if(str.size() == max*2){	// condition reach so we append that string to the ans
			ans.push_back(str);
			return;
		}
		if(close>open){	// illegal condition so we return
			return;
		}
		if(open<max){	// add opening parenthesis and apply recursion
			dfs(ans, str+"(", open+1, close, max);
		}
		if(close<open){		// add closing parenthesis 
			dfs(ans, str+")", open, close+1, max);
		}
	}
};