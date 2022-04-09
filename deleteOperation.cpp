#include "test.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len = lcs(word1, word2);
        return word1.size()+word2.size() - (2*len);
    }
    
    int lcs(string word1, string word2){
        int m=word1.size(), n=word2.size();
        vector<vector<int>>memo(m+1, vector<int>(n+1));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1] == word2[j-1]){
                    memo[i][j] = 1+memo[i-1][j-1];
                }    
                else{
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                }
            }
        }
        return memo[m][n];
    }
};