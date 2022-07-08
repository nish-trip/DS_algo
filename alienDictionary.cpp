#include "test.h"

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_set<int>seen(26);
        for(string word: words){
            for(char c: word){
                seen.insert(c-'a');
            }
        }
        vector<vector<int>>adj(26);
        for(int i=0; i<words.size()-1; i++){
            int l1 = words[i].size();
            int l2 = words[i+1].size();
            int len = min(l1, l2);
            if(l1>l2 && words[i].substr(0,len) == words[i+1]){
                return "";
            }
            for(int j=0; j<len; j++){
                if(words[i][j] != words[i+1][j]){
                    adj[words[i][j] - 'a'].push_back(words[i+1][j]-'a');
                    break;
                }
            }
        }
        string ans = "";
        vector<int>visited(26);
        for(int i: seen){
            if(!visited[i]){
                if(dfs(adj, i, visited, ans)){
                    return "";
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    bool dfs(vector<vector<int>>& adj, int i, vector<int>& visited, string& ans){
        if(visited[i] == 1) return true;
        if(visited[i] == 2) return false;
        visited[i] = 1;
        for(int num: adj[i]){
            if(dfs(adj, num, visited, ans)){
                return true;
            }
        }
        visited[i] = 2;
        ans += (char)('a'+i);
        return false;
    }
};