class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        const int m = board.size();
        const int n = board[0].size();
        if (m * n < word.size()) return false;
        vector<vector<bool>>used(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (exist(board, used, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
private:
    bool exist(vector<vector<char>>& board, vector<vector<bool>>& used, string word, int pos, int i, int j){
        if (pos == word.size()) return true;
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (used[i][j]) return false;
        if (board[i][j] != word[pos]) return false;
        
        used[i][j] = true;
        bool ok = exist(board, used, word, pos + 1, i - 1, j) ||
                  exist(board, used, word, pos + 1, i + 1, j) ||
                  exist(board, used, word, pos + 1, i, j - 1) ||
                  exist(board, used, word, pos + 1, i, j + 1);
        if(ok) return true;
        else{
            used[i][j] = false;
            return false;
        }
    }
};
