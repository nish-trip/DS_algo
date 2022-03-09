#include "test.h"

class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        int ans=0, n=heights.size();
        vector<int> left(n), right(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            left[i] = st.empty()?0: st.top()+1;
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            right[i] = st.empty()?n-1: st.top()-1;
            st.push(i);
        }
        for(int i=0; i<n; i++){
            ans = max(ans, heights[i]*(right[i]-left[i]+1));
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        int maxArea = 0;
        vector<int>nums(m);
        for(int row=0; row<n; row++){
            for(int j=0; j<m; j++){
                if(matrix[row][j] == '1'){
                    nums[j]++;
                }
                else{
                    nums[j] = 0;
                }
            }
            int area = largestRectangleArea(nums);
            maxArea = max(maxArea, area);
        }   
        return maxArea;   
    }
};