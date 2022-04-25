#include "test.h"

class Solution {
public:
    bool judgeSquareSum(int c) {
        long l=0, r=sqrt(c);
        while(l<=r){
            long sum = (l*l) + (r*r);
            if(sum == c){
                return true;
            }
            if(sum>c){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }
    
    int sqrt(int num){
        long l=0, r=num, ans = 0;
        while(l<=r){
            long m=l+(r-l)/2;
            if(m*m == num){
                return (int)m;
            }
            else if(num> m*m){
                l = m+1;
                ans  = m;
            }
            else{
                r = m-1;
            }
        }
        return (int)ans;
    }
};