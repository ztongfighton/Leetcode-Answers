class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        string nums;
        for (char c = '1'; c <= '0' + n; ++c)
            nums.push_back(c);
        k = k - 1;
        int i = n - 1;
        while (i > 0){
            int base = factorial(i);
            int pos = k / base;
            result.push_back(nums[pos]);
            k = k % base;
            --i;
            nums.erase(pos, 1);
        }
        result.push_back(nums[0]);
        return result;
    }
private:
    int factorial(int n){
        int result = 1;
        for (int i = 1; i <= n; ++i)
            result *= i;
        return result;
    }
};
