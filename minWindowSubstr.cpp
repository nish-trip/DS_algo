#include "test.h"

class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int minLen = INT_MAX;
        unordered_map<char,int>hash;
        for(char c: t){
            hash[c]++;
        }
        int count = hash.size();
        int start = 0;
        for(int end=0; end<s.size(); end++){
            if(hash.count(s[end])){
                hash[s[end]]--;
                if(!hash[s[end]]){
                    count--;
                }
            }
            while(!count){
                if(end-start+1 < minLen){
                    minLen = end-start+1;
                    ans = s.substr(start, minLen);
                }
                if(hash.count(s[start])){
                    hash[s[start]]++;
                    if(hash[s[start]]>0){
                        count++;
                    }
                }
                start++;
            }
        }
        return ans;
    }
};