class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);      
    }

    bool solve(vector<vector<char>>& grid, int i, int j){
        if(i==9) return true;
        if(j==9){
            return solve(grid, i+1, 0);
        }
        if(grid[i][j] != '.') return solve(grid, i, j+1);
        for(char c='1'; c<='9'; c++){
            if(valid(grid, i, j, c)){
                grid[i][j] = c;
                if(solve(grid, i, j+1)){
                    return true;
                }
                grid[i][j] = '.';
            }
        }
        return false;
    }

    bool valid(vector<vector<char>>& grid, int i, int j, char c){
		for(int k=0; k<9; k++){
			if(grid[i][k] == c){
				return false;
			}
		}
		for(int k=0; k<9; k++){
			if(grid[k][j] == c){
				return false;
			}
		}
		int I=i-(i%3), J=j-(j%3);
		for(int a=0; a<3; a++){
			for(int b=0; b<3; b++){
				if(c == grid[I+a][J+b]){
					return false;
				}
			}
		}
		return true;
    }
};