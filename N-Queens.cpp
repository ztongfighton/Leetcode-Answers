class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if (n < 1) return result;
        vector<string> path;
        vector<bool> col(n, false);
        vector<bool> diag(2 * n, false);
        vector<bool> anti_diag(2 * n, false);
        dfs(result, path, col, diag, anti_diag, 0, n);
        return result;
    }
    
private:
    void dfs(vector<vector<string>>& result, vector<string>& path, vector<bool>& col, vector<bool>& diag, vector<bool>& anti_diag, int row, int n){
        if (row == n){
            result.push_back(path);
            return;
        }
        for (int j = 0; j < n; ++j){
            if (col[j] || diag[n - row + j - 1] || anti_diag[row + j]) continue;
            else{
                col[j] = diag[n - row + j - 1] = anti_diag[row + j] = true;
                string s;
                for (int k = 0; k < n; ++k){
                    if (k != j) s += '.';
                    else s += 'Q';
                }
                path.push_back(s);
                dfs(result, path, col, diag, anti_diag, row + 1, n);
                path.pop_back();
                col[j] = diag[n - row + j - 1] = anti_diag[row + j] = false;
            }
        }
    }
};
