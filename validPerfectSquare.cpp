#include <bits/stdc++/h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 1, r = num;
        while(l<=r){
            long m = l+(r-l)/2;
            if(m*m == num){
                return true;
            }
            if(num > m*m){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }   
        return false;   
    }
};
