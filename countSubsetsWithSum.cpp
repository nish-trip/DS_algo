#include "test.h"

class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        // Given an array arr[] of integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.
        vector<vector<int>>memo(n+1, vector<int>(sum+1));
        for(int i=0; i<=n; i++){
            memo[i][0] = 1;
        }
        for(int i=1; i<=sum; i++){
            memo[0][i] = 0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(arr[i-1]>j){
                    memo[i][j] = memo[i-1][j];
                }
                else{
                    memo[i][j] = memo[i-1][j]+memo[i-1][j-arr[i-1]];
                }
            }
        }
        return memo[n][sum];
	}
	  
};