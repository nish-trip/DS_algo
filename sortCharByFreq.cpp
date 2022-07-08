#include "test.h"

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>hash;
        vector<string>buckets(s.size()+1, "");
        for(char c: s){
            hash[c]++;
        }
        for(auto i: hash){
            int n = i.second;
            int c = i.first;
            buckets[n].append(n,c);
        }
        reverse(buckets.begin(), buckets.end());
        string ans = "";
        for(string str: buckets){
            if(str.size()>0){
                ans+= str;
            }
        }
        return ans;
    }
};