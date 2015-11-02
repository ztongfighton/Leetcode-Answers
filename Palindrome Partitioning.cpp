class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        const int n = s.size();
        if (n < 1) return result;
        vector<vector<bool>> f(n, vector<bool>(n, false));
        isPalindrome(s, f);
        vector<string> path;
        findPath(s, result, path, f, 0, n);
        return result;
    }

private:
    void isPalindrome(string s, vector<vector<bool>>& f){
        const int n = s.size();
        for (int j = 0; j < n; ++j){
            for (int i = j; i >= 0; --i){
                if (i == j) f[i][j] = true;
                else if (j - i == 1){
                    if (s[i] == s[j]) f[i][j] = true;
                    else f[i][j] = false;
                }
                else{
                    if (f[i + 1][j - 1] && s[i] == s[j])
                        f[i][j] = true;
                    else
                        f[i][j] = false;
                }
            }
        }
    }
    
    void findPath(string& s, vector<vector<string>>& result, vector<string>& path, vector<vector<bool>>& f, int start, int end){
        if (start == end){
            result.push_back(path);
            return;
        }
        for (int i = start; i < end; ++i){
            if (f[start][i]){
                path.push_back(s.substr(start, i - start + 1));
                findPath(s, result, path, f, i + 1, end);
                path.pop_back();
            }
        }
    }
};
