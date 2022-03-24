#include "test.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>path;
        vector<vector<int>>paths;
        sort(nums.begin(), nums.end());
        dfs(nums, path, paths, 0);
        return paths;      
    }

    void dfs(vector<int>& nums, vector<int>& path, vector<vector<int>>& paths, int index){
        paths.push_back(path);
        for(int i=index; i<nums.size(); i++){
            if(i>index && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            dfs(nums, path, paths, i+1);
            path.pop_back();
        }
    }
};