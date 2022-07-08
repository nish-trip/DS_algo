#include "test.h"

class Solution {
public:
    static bool compare(string a, string b){
        return a.size()<b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int>hash;
        //hash[""] = 0;
        sort(words.begin(), words.end(), compare);
        int ans = 1;
        for(string word: words){
            hash[word] = 1;
            for(int i=0; i<word.size(); i++){
                string temp = word.substr(0,i)+word.substr(i+1);
                if(hash.count(temp)){
                    hash[word] = max(hash[word], 1+hash[temp]);
                    ans = max(ans, hash[word]);
                }
            }
        }
        return ans;
    }
};