#include "test.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>>memo(s.size()+1, vector<bool>(p.size()+1));
        memo[0][0] = true;

        // we know that '*' will alway have a . or char before it
        // there for pattern to match empty string, '*' must occur at odd indices and memo[i][j-2] must also be valid  
        for(int j=2; j<=p.size(); j+=2){
            if(p[j-1] == '*' && memo[0][j-2]){
                memo[0][j] = true;
            }
        }      

        for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=p.size(); j++){
                // in this case the character of string and pattern match 
                if(s[i-1] == p[j-1] || p[j-1] == '.'){
                    memo[i][j] = memo[i-1][j-1];
                }
                // incase its * then
                else if(p[j-1] == '*'){
                    
                    if(p[j-2] != '.' && p[j-2] != s[i-1]){  // char* matches empty string since the character before * in the pattern doesn't the current string character 
                        memo[i][j] = memo[i][j-2];
                    }
                    else{   // if '.' precedes '*' or if the charactes match then 
                        memo[i][j] = memo[i-1][j] || memo[i-1][j-2] || memo[i][j-2];
                    }
                }
            }
        }
        return memo[s.size()][p.size()];
    }
};