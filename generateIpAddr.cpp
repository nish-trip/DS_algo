#include "test.h"

class Solution{
  public:
    vector<string> genIp(string &s) {
        // Your code here
        int n=s.size();
        if(n<4) return {};
        vector<int>cur(4);
        vector<string>ans;
        dfs(s, 0, cur, ans, 0);
        return ans;
    }
    
    void dfs(string& s, int index, vector<int>& cur, vector<string>& ans, int segment){
        if(segment == 4 && index == s.size()){
            string str = to_string(cur[0])+"."+to_string(cur[1])+"."+to_string(cur[2])+"."+to_string(cur[3]);
            ans.push_back(str);
            return;
        }
        if(segment == 4||index == s.size()){
            return;
        }
        for(int len=1; len<=3 && len+index<=s.size(); len++){
            string numstr = s.substr(index, len);
            int num = stoi(numstr);
            if(num>255 || len>=2 && numstr[0] == '0'){
                break;
            }
            cur[segment] = num;
            dfs(s, index+len, cur, ans, segment+1);
            cur[segment] = -1;
        }
    }
};