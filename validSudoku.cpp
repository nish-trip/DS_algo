class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& grid) {
        vector<unordered_set<char>>rowSet(9);      
        vector<unordered_set<char>>colSet(9);      
        vector<unordered_set<char>>squareSet(9);
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(grid[i][j] == '.'){
                    continue;
                }
                char c = grid[i][j];
                int x = (i/3)*3 + (j/3);
                if(rowSet[i].count(c) || colSet[j].count(c) || squareSet[x].count(c)){
                    return false;
                }
                rowSet[i].insert(c);
                colSet[j].insert(c);
                squareSet[x].insert(c);
            }
        }      
        return true;
    }
};