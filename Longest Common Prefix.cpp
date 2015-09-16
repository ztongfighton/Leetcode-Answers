class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int n = strs.size();
        if (n == 0) return "";
        if (n == 1) return strs[0];
        const int m = strs[0].size();
        for (int i = 0; i < m; ++i){
            for (int j = 1; j < n; ++j){
                if (strs[0][i] != strs[j][i]) return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
