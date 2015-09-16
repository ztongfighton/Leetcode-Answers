class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        if (s.empty()) return result;
        string symbol = "MDCLXVI";
        const int radix[] = {1000, 500, 100, 50, 10, 5, 1};
        const int n = s.size();
        for (int i = 0; i < n;){
            int num1 = radix[symbol.find(s[i])];
            int num2 = i < n - 1 ? radix[symbol.find(s[i + 1])] : 0;
            if (num1 < num2) {
                result += num2 - num1;
                i += 2;
            }
            else {
                result += num1;
                ++i;
            }
        }
        return result;
    }
};
