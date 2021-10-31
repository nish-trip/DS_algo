#include<bits/stdc++.h>
using namespace std;

/*
function dfs(node, state):
    if state is a solution:
        report(state) # e.g. add state to final result list
        return

    for child in children:
        if child is a part of a potential solution:
            state.add(child) # make move
            dfs(child, state)
            state.remove(child) # backtrack

*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> paths;
		vector<int>path;
        sort(candidates.begin(), candidates.end());
		dfs(candidates, target, path, paths, 0);
		return paths;
    }

	void dfs(vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& paths, int i){
		if(target<0) return;
		if(target==0){
			paths.push_back(path);
		}
		else{
			for(int j=i; j<candidates.size(); j++){
				if(j>i && candidates[j]==candidates[j-1]){
					continue;
				}
				path.push_back(candidates[j]);
				dfs(candidates, target-candidates[j], path, paths, j+1);
				path.pop_back();
			}
		}
	}
};