class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n < 1) return result;
        string s = "(";
        dfs(result, s, 1, 0, n);
        return result;
    }
    
private:
    void dfs(vector<string>& result, string s, int left, int right, int n){
        if (left == n){
            if (right < n) s.append(n - right, ')');
            result.push_back(s);
            return;
        }
        
        dfs(result, s + '(', left + 1, right, n);
        if (left > right)
            dfs(result, s + ')', left, right + 1, n);
    }
    
};
