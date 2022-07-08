#include "test.h"

class Solution {
public:
    int uniqueLetterString(string s) {
		int n = s.length();
        int mod = 1e9 + 7;
		vector<long long> left(n), right(n);
		vector<long long> lastLeft(26, -1), lastRight(26, n);
		for (int i = 0; i < n; i++){
			left[i] = i - lastLeft[s[i] - 'A'];
			lastLeft[s[i] - 'A'] = i;
		}     
		for (int i = n-1; i >= 0; i--){
			right[i] = lastRight[s[i] - 'A'] - i;
			lastRight[s[i] - 'A'] = i;
		}   
		int ans = 0; 

		for (int i = 0; i < n; i++){
            int temp = (left[i]*right[i])%mod;
			ans = (ans + temp) % mod;
		}
		return ans;
    }
};