class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        stack<char> stk;
        string left = "({[";
        string right = ")}]";
        for (auto i = s.begin(); i != s.end(); ++i){
            if (stk.empty()) stk.push(*i);
            else{
                size_t j = left.find(*i, 0);
                if (j != string::npos) stk.push(*i);
                else{
                    j = right.find(*i, 0);
                    if (stk.top() != left[j]) return false;
                    else stk.pop();
                }
            }
        }
        return stk.empty();
    }
};
