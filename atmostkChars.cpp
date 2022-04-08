#include "test.h"

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int len=0, start=0;
        unordered_map<char,int>hash;
        for(int end=0; end<s.size(); end++){
            hash[s[end]]++;
            while(hash.size()>k){
                hash[s[start]]--;
                if(!hash[s[start]]){
                    hash.erase(s[start]);
                }
                start++;
            }
            len = max(len, end-start+1);
        }
        return len;
    }
};