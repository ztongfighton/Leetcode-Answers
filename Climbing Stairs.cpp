class Solution {
public:
    int climbStairs(int n) {
        int cur = 1;
        int prev = 0;
        for (int i = 1; i <= n; ++i){
            int tmp = cur;
            cur += prev;
            prev = tmp;
        }
        return cur;
    }
};
