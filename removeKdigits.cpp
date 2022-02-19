#include "test.h"

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(!num.size()){
            return "0";
        }      
        stack<int>st;
        for(char c: num){
            while(k && !st.empty() && st.top()>c){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k && !st.empty()){
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        while(ans.front() == '0'){
            ans.erase(ans.begin());
        }
        return ans.size()? ans: "0";
    }
};