class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty()) return;
        const int m = board.size();
        const int n = board[0].size();
        if (m != 9 || n != 9) return;
        solver(board);
    }
    
private:
    bool solver(vector<vector<char>>& board){
        bool complete = true;
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j){
                if (board[i][j] == '.'){
                    complete = false;
                    vector<bool>used(9, false);
                    for (int m = 0; m < 9; ++m){
                        if (board[i][m] != '.'){
                            used[board[i][m] - '1'] = true;
                        }
                    }
                    
                    for (int n = 0; n < 9; ++n){
                        if (board[n][j] != '.'){
                            used[board[n][j] - '1'] = true;
                        }
                    }
                    
                    int ii = i / 3, jj = j / 3;
                    for (int m = ii * 3; m < ii * 3 + 3; ++m){
                        for (int n = jj * 3; n < jj * 3 + 3; ++n){
                            if (board[m][n] != '.'){
                                used[board[m][n] - '1'] = true;
                            }
                        }
                    }
                    
                    for (int k = 0; k < 9; ++k){
                        if (used[k] == false){
                            board[i][j] = k + '1';
                            if(solver(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        if (complete) return true;
    }
};
