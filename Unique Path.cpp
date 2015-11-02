class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[m][n];
        fill_n(&f[0][0], m * n, 0);
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (i == 0 && j == 0) f[i][j] = 1;
                else f[i][j] = (i >= 1 ? f[i - 1][j] : 0) + (j >= 1 ? f[i][j - 1] : 0);
            }
        }
        return f[m - 1][n - 1];
    }
};
