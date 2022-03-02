#include "test.h"

TreeNode* getSuccessor(TreeNode* node, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode* ans = NULL;
    while(node){
        if(B<node->val){
            ans = node;
            node = node->left;
        }
        else{
            node = node->right;
        }
    }
    return ans;
}