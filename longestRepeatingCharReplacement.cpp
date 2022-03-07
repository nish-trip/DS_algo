#include "test.h"

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, maxCount=0;
        vector<int>count(26,0);
        int start=0;
        for(int end=0; end<s.size(); end++){
            maxCount = max(maxCount, ++count[s[end]-'A']);
            while(end-start+1-maxCount > k){
                count[s[start]-'A']--;
                start++;
            }
            maxLen = max(maxLen, end-start+1);
        }      
        return maxLen;
    }
};