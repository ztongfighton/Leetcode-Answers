class Solution {
public:
    int numTrees(int n) {
        vector<int> s(n + 1, 0);
        s[0] = 1;
        s[1] = 1;
        for (int i = 2; i <= n; ++i){
            for (int k = 0; k < i; ++k){
                s[i] += s[k] * s[i - 1- k];
            }
        }
        return s[n];
    }
};
