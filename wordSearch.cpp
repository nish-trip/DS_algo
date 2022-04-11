#include "test.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(dfs(board,word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word,int i, int j, int index){
        if(index == word.size()){
            return true;
        }
        if(i<0 || j<0|| i>=board.size() || j>=board[0].size() || board[i][j] != word[index]){
            return false;
        }
        board[i][j] = '*'; // change the content, to avoid duplicated search
        bool furtherSearch =  dfs(board, word, i+1, j, index+1) || // up
                              dfs(board, word, i-1, j, index+1) || // down
                              dfs(board, word, i, j-1, index+1) || // left
                              dfs(board, word, i, j+1, index+1);   // right
        
        board[i][j] = word[index]; // modify it back!
        return furtherSearch;
    }
};