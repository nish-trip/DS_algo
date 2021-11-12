#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start=0, end=0;
        for(int i=0; i<s.size(); i++){
            int l1 = expand(s, i, i);
            int l2 = expand(s, i, i+1);
            int len = max(l1, l2);
            if(len>end-start){
                start = i - ((len-1)/2);
                end = i+(len/2);
            }
        }      
        return s.substr(start, end-start+1);
    }
    int expand(string str, int start, int end){
        if(start>end) return 0;
        while((start>=0 && end<str.size()) && str[start] == str[end]){
            start--;
            end++;
        }
        return end-start-1;
    }
};
