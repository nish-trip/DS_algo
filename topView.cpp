#include "test.h"

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(!root){
            return ans;
        }
        queue<pair<int,Node*>>q;
        q.push({0,root});
        map<int,int>hash;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int line = front.first;
            Node* node = front.second;
            if(!hash.count(line)){
                hash[line] = node->data;
            }
            if(node->left){
                q.push({line-1, node->left});
            }
            if(node->right){
                q.push({line+1, node->right});
            }
        }
        for(auto i: hash){
            ans.push_back(i.second);
        }
        return ans;
    }

};