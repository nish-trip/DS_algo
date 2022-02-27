#include "test.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, end=-1;
        stack<int>st;
        for(int i=0; i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(st.empty()){
                end = i;
            }
            else{
                st.pop();
                int start = st.empty()? end+1: st.top()+1;
                ans = max(ans, i-start+1);
            }
        }      
        return ans;
    }
};