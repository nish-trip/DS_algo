class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>>ans;
		if(nums.size()<3){
			return ans;
		}
        sort(nums.begin(), nums.end());
		for(int i=0; i<nums.size()-2; i++){
			if(i>0 && nums[i]==nums[i-1]){
				continue;
			}
			int start = i+1, end=nums.size()-1, sum = -nums[i];
			while(start<end){
				if(nums[start]+nums[end]==sum){
					ans.push_back({nums[i], nums[start], nums[end]});
					while(start<end && (nums[start] == nums[start+1])){
						start++;
					}
					while(start<end && (nums[end] == nums[end--])){
						end--;
					}
					start++, end--;
				}
				else if(nums[start]+nums[end]<sum){
					start++;
				}
				else{
					end--;
				}
			}
		}
		return ans;
    }
};