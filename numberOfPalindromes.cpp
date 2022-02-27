#include "test.h"

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>>memo(s.size()+1, vector<int>(s.size()+1));
        int count = 0;
        for(int i=0; i<s.size(); i++){
            for(int j=i; j>=0; j--){
                if(i==j){
                    memo[i][j] = 1;
                }
                else if(i-j == 1){
                    memo[i][j]= s[i]==s[j];
                }
                else{
                    memo[i][j] = s[i]==s[j]? memo[i-1][j+1]:0;
                }
                count+= memo[i][j];
            }
        }
        return count;
    }
};