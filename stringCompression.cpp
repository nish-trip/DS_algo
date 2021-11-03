#include<bits.stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& str) {
        // str = ["a","a","b","b","c","c","c"]
        int index = 0, i=0;
        int j;
        while(i<str.size()){
            j = i+1;
            while(j<str.size() && str[i] == str[j]){
                j++;
            }
            str[index++] = str[i];
            if(j-i > 1){
                string nums = to_string(j-i);
                for(char num : nums){
                    str[index++] = num;
                }
            }
            i=j;
        }
        return index;
    }
};
