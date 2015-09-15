class Solution {
public:
    int strStr(string haystack, string needle) {
        const int m = haystack.size();
        const int n = needle.size();
        if (n == 0) return 0;
        if (m < n) return -1;
        for (int i = 0; i <= m - n; ++i){
            bool found = true;
            for (int j = 0; j < n; ++j){
                if (haystack[i + j] != needle[j]){
                    found = false;
                    break;
                }
            }
            
            if (found) return i;
        }
        return -1;
    }
};
