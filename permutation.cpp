#include "test.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>path;
        vector<vector<int>>paths;
        sort(nums.begin(), nums.end());
        vector<bool>used(nums.size());
        dfs(nums, used, path, paths);
        return paths;
    }

    void dfs(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& paths){
        if(path.size() == nums.size()){
            paths.push_back(path);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(used[i] || i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used, path, paths);
            path.pop_back();
            used[i] = false;
        }
    }
};