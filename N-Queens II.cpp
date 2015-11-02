class Solution {
public:
    int totalNQueens(int n) {
        this->count = 0;
        if (n < 1) return this->count;
        vector<bool> col(n, false);
        vector<bool> diag(2 * n, false);
        vector<bool> anti_diag(2 * n, false);
        dfs(col, diag, anti_diag, 0, n);
        return this->count;
        
    }
private:
    int count;
    void dfs(vector<bool>& col, vector<bool>& diag, vector<bool>& anti_diag, int row, int n){
        if (row == n){
            ++count;
            return;
        }
        for (int j = 0; j < n; ++j){
            if (col[j] || diag[n - row + j - 1] || anti_diag[row + j]) continue;
            else{
                col[j] = diag[n - row + j - 1] = anti_diag[row + j] = true;
                dfs(col, diag, anti_diag, row + 1, n);
                col[j] = diag[n - row + j - 1] = anti_diag[row + j] = false;
            }
        }
    }
    
};
