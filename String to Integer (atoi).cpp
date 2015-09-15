class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        const int n = str.size();
        int i = 0;
        while (i < n && str[i] == ' ') ++i;
        if (i == n) return result;
        
        int sign = 1;
        if (str[i] == '+') ++i;
        else if (str[i] == '-') {sign = -1; ++i;};
        
        while (i < n && str[i] >= '0' && str[i] <= '9'){
            int j = str[i] - '0';
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && j > (sign == 1 ? INT_MAX % 10 : INT_MAX % 10 + 1))) return sign == 1 ? INT_MAX : INT_MIN;
            else result = result * 10 + j;
            ++i;
        }
        
        return sign == 1 ? result : -result;
    }
};
