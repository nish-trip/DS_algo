#include "test.h"

class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(char c: s){
            if(c != ']'){
                string str = "";
                str += c;
                st.push(str);
            }
            else{
                string word = "";
                while(!st.empty() && st.top() != "["){
                    word+= st.top();
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    num = st.top()+num;
                    st.pop();
                }
                int number = stoi(num);
                string temp = word;
                while(--number){
                    word+= temp;
                }
                st.push(word);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};