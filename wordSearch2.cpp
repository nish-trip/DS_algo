#include "test.h"

class Solution {
public:
    class trienode{
    public:
        char data;
        int ew;
        trienode* children[26];
    };
    
    trienode* root;
    
    void init(){
        root = new trienode();
        root->data = '/';
        root->ew = 0;
        for(int i=0; i<26; i++){
            root->children[i] = NULL;
        }
    }
    
    trienode* getNode(char c){
        trienode* node = new trienode();
        node->data = c;
        node->ew = 0;
        for(int i=0; i<26; i++){
            node->children[i] = NULL;
        }
        return node;
    }
    
    void insert(string word){
        trienode* cur = root;
        for(char c: word){
            int index = c-'a';
            if(cur->children[index] == NULL){
                cur->children[index] = getNode(c);
            }
            cur = cur->children[index];
        }
        cur->ew++;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m= board.size(), n=board[0].size();
        vector<string>ans;
        init();
        for(string word: words){
            insert(word);
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                trienode* cur = root;
                string str = "";
                dfs(board, i, j, ans, str, cur);
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, vector<string>& ans, string str, trienode* cur){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] == '*'){
            return;
        }
        int index = board[i][j]-'a';
        if(cur->children[index] == NULL){
            return;
        }
        trienode* child = cur->children[index];
        str.push_back(board[i][j]);
        if(child->ew && find(ans.begin(), ans.end(), str) == ans.end()){
            ans.push_back(str);
        }
        char data = board[i][j];
        board[i][j] = '*';
        
        dfs(board, i+1, j, ans, str, child);
        dfs(board, i-1, j, ans, str, child);
        dfs(board, i, j+1, ans, str, child);
        dfs(board, i, j-1, ans, str, child);
        
        board[i][j] = data;
    }
};