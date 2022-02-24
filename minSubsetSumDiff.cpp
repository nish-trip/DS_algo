#include "test.h"
    
    
    int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i=0; i<n; i++){
	        sum+= arr[i];
	    }
	    int target=sum;
	    //divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference
	    // minimise sum-2s1
	    // assuming that s1<=s2 =>  s1<=sum/2
	    sum/=2;
	    vector<vector<bool>>memo(n+1, vector<bool>(sum+1));
	    for(int i=0; i<=n; i++){
	        memo[i][0] = true;
	    }
	    for(int i=1; i<=sum; i++){
	        memo[0][i] = false;
	    }
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=sum; j++){
	            if(j>=arr[i-1]){
	                memo[i][j] = memo[i-1][j] || memo[i-1][j-arr[i-1]];
	            }
	            else{
	                memo[i][j] = memo[i-1][j];
	            }
	        }
	    }
	    int ans =target;
	    for(int j=sum; j>=0; j--){
	        if(memo[n][j]){
	            ans = min(ans, target-(2*j));
	        }
	    }
	    return ans;
	}