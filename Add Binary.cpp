class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        const int m = a.size();
        const int n = b.size();
        if (m > n) b.insert(0, m - n, '0');
        if (m < n) a.insert(0, n - m, '0');
        string result;
        for (int i = max(m, n) - 1; i >= 0; --i){
            int sum = carry + a[i] - '0' + b[i] - '0';
            result.insert(result.begin(), sum % 2 + '0');
            carry = sum / 2;
        }
        
        if (carry > 0) result.insert(result.begin(), '1');
        return result;
    }
};
