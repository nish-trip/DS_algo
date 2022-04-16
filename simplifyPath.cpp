#include "test.h"

class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        stack<string>st;
        for(int i=0; i<path.size(); i++){
            if(path[i]=='/'){
                continue;
            }
            string temp = "";
            while(i<path.size() && path[i] != '/'){
                temp+= path[i];
                i++;
            }
            if(temp == "" || temp == "."){
                continue;
            }
            else if(temp == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(temp);
            }
        }
        if(st.empty()){
            return "/";
        }
        while(!st.empty()){
            ans = "/"+st.top()+ans;
            st.pop();
        }
        return ans;
    }
};