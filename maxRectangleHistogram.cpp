#include "test.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // the largest rectangle contains atleast one of bar completely
        int ans =0;
        vector<int>left(heights.size()), right(heights.size());
        stack<int>st;
        // we iterate through the heights and the left most index wher ethis bar can be contained completely 
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            left[i] = st.empty()? 0: st.top()+1;
            st.push(i);
        }      
        // we empty the stack
        while(!st.empty()){
            st.pop();
        }
        // iterate through the heights and find the rightmost index such that the current bar can be contained completely
        for(int i=heights.size()-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            right[i] = st.empty()? heights.size()-1: st.top()-1;
            st.push(i);
        }
        // iterate through the heights and find the max area possible 
        for(int i=0; i<heights.size(); i++){
            ans = max(ans, heights[i]*(right[i]-left[i]+1));
        }
        return ans;
    }
};