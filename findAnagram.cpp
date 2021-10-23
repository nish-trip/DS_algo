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

//conditions for anagram:
// 1) size of the strings should be same
// 2) count==0 ,ie, the frequency off characters should be the same
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
		vector<int>ans;
		if(!s.size()){
			return ans;
		}
		unordered_map<char,int>hash;
		for(char c: p){
			hash[c]++;
		}
		int count = hash.size();
		int begin=0;

		for(int end=0; end<s.size();end++){
			char endchar = s[end];
			if(hash.count(endchar)){
				hash[endchar]--;
				if(hash[endchar] == 0){
					count--;
				}
			}
			while(count == 0){
				if(p.size() == end-begin+1){
					ans.push_back(begin);
				}
				char begchar = s[begin];
				if(hash.count(begchar)){
					hash[begchar]++;
					if(hash[begchar] > 0){
						count++;
					}
				}
				begin++;
			}
		}
		return ans;
    }
};

