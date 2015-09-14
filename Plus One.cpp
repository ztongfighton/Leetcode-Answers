class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return digits;
        const int n = digits.size();
        int c = 1;
        for (int i = n - 1; i >= 0; --i){
            int sum = digits[i] + c;
            digits[i] = sum % 10;
            c = sum / 10;
        }
        if (c != 0) digits.insert(digits.begin(), c);
        return digits;
    }
};
