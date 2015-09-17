class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        int maxlen = 0;
        stack<int> left;
        int right = -1;
        const int n = s.size();
        for (int i = 0; i < n; ++i){
            if (s[i] == '(') left.push(i);
            else{
                if (left.empty()){
                    right = i;
                }
                else{
                    left.pop();
                    if (left.empty()) maxlen = max(maxlen, i - right);
                    else maxlen = max(maxlen, i - left.top());
                }
            }
        }
        return maxlen;
    }
};
