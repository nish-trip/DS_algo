class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        if(!n) return ans;
        vector<string>board(n, string(n,'.'));
        backTrack(0, board, ans);
        return ans;      
    }

    void backTrack(int row, vector<string>& board, vector<vector<string>>& ans){
        if(row == board.size()){
            ans.push_back(board);
            return;
        }
        for(int i=0; i<board.size(); i++){
            if(valid(row, i, board)){
                board[row][i] = 'Q';
                backTrack(row+1, board, ans);
                board[row][i] = '.';
            }
        }
    }

    bool valid(int row, int col, vector<string>& board){
        for(int i=row; i>=0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        for(int i=row, j=col; i>=0 && j>=0; i--,j--){
            if(board[i][j] =='Q'){
                return false;
            }
        }
        for(int i=row, j=col; i>=0 && j<board.size(); i--,j++){
            if(board[i][j] =='Q'){
                return false;
            }         
        }
        return true;
    }
};