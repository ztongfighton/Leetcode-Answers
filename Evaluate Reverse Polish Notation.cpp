class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result = 0;
        if (tokens.empty()) return result;
        const int n = tokens.size();
        stack<int> stk;
        for (int i = 0; i < n; ++i){
            if (!isOperator(tokens[i])) stk.push(stoi(tokens[i]));
            else{
                int num1 = stk.top(); stk.pop();
                int num2 = stk.top(); stk.pop();
                if (tokens[i] == "+") stk.push(num2 + num1);
                else if (tokens[i] == "-") stk.push(num2 - num1);
                else if (tokens[i] == "*") stk.push(num2 * num1);
                else stk.push(num2 / num1);
            }
        }
        return stk.top();
    }
    
private:
    bool isOperator(string &s){
        if (s == "+" || s == "-" || s == "*" || s == "/") return true;
        else return false;
    }
};
