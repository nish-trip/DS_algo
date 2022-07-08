#include "test.h"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int i=0;
        int n = pushed.size();
        for(int num: pushed){
            st.push(num);
            while(!st.empty() && i<n && st.top() == popped[i]){
                st.pop();
                i++;
            }
        }
        return i==n;
    }
};