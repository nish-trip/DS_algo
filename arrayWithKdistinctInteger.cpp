#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
		return atMost(nums,k)-atMost(nums, k-1); 
    }

    int atMost(vector<int>& arr, int k)
    {
        int count = 0;
        int left = 0;
        unordered_map<int,int> map;
        for(int right = 0; right<arr.size(); right++) {
            map[arr[right]]++;
            while (map.size() > k) {
                map[arr[left]] --;
                if (map[arr[left]] == 0){
                    map.erase(arr[left]);
                }
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};