class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return s;
        const int n = s.size();
        bool p[n][n];
        fill_n(&p[0][0], n * n, false);
        for (int i = 0; i < n; ++i)
            p[i][i] = true;
        for (int i = n - 2; i >= 0; --i){
            for (int j = i + 1; j < n; ++j){
                if (j - i < 2) p[i][j] = s[i] == s[j];
                else p[i][j] = p[i + 1][j - 1] && (s[i] == s[j]);
            } 
        }
        
        int maxlen = 0, start = -1, end = -1;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (p[i][j] && j - i + 1 > maxlen){
                    maxlen = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
