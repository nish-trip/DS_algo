#include "test.h"

class Solution {
public:
    int numWays(int n, int k) {
        if(n==1) return k;
        if(n==2) return k*k;
        vector<int>dp(n+1);
        dp[0] = 0;
        dp[1] = k;
        dp[2] = k*k;
        // numways[i] = diff[i] + diff[i-1]
        for(int i=3; i<=n; i++){
            dp[i] = (dp[i-1]*(k-1)) + (dp[i-2]*(k-1));
        }
        return dp[n];
    }
};

/*
If you are painting the ith post, you have two options:
1) make it different color as i-1th post
2) make it same color as i-1 th post (if you are allowed!)

simply add these for your answer:
num_ways(i) = num_ways_diff(i) + num_ways_same(i)

Now just think of how to calculate each of those functions.

The first one is easy. If you are painting the ith post, how many ways can you paint it to make it different from the i-1 th post? k-1

num_ways_diff(i) = num_ways(i-1) * (k-1)

The second one is hard, but not so hard when you think about it.

If you are painting the ith post, how many ways can you paint it to make it the same as the i-1th post? At first, we should think the answer is 1 -- it must be whatever color the last one was.

num_ways_same(i) = num_ways(i-1) * 1

But no! This will fail in the cases where painting the last post the same results in three adjacent posts of the same color! We need to consider ONLY the cases where the last two colors were different. But we can do that!

num_ways_diff(i-1) <- all the cases where the i-1th and i-2th are different.

THESE are the cases where can just plop the same color to the end, and no longer worry about causing three in a row to be the same.

num_ways_same(i) = num_ways_diff(i-1) * 1

*/