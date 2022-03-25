#include "test.h"

class Solution {
public:
    int countVowelSubstrings(string word) {
        return atMost(word,5) - atMost(word,4);
    }

    int atMost(string word, int num){
        unordered_map<char,int>hash;
        int ans=0, start=0;
        for(int end=0; end<word.size(); end++){
            if(!isVowel(word[end])){
                hash.clear();
                start = end+1;
                continue;
            }
            hash[word[end]]++;
            while(hash.size()>num){
                hash[word[start]]--;
                if(!hash[word[start]]){
                    hash.erase(word[start]);
                }
                start++;
            }
            ans+= end-start+1;
        }
        return ans;
    }

    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }
};