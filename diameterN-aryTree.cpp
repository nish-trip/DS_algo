#include "test.h"

class Solution {
public:
    int diameter(Node* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
    int dfs(Node* root, int& ans){
        if(!root) return 0;
        int firstMax = 0, secondMax = 0;
        for(Node* child: root->children){
            int childheight = dfs(child, ans);
            if(childheight > firstMax){
                secondMax = firstMax;
                firstMax = childheight;
            }
            else if(childheight > secondMax){
                secondMax = childheight;
            }
        }
        ans = max(ans, firstMax+secondMax);
        return firstMax+1;
    }
};