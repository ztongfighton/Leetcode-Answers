class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        const int len = 1 << n;
        result.reserve(len);
        result.push_back(0);
        for (int i = 0; i < n; ++i){
            int highest_bit = 1 << i;
            for (int j = result.size() - 1; j >= 0; --j)
                result.push_back(highest_bit | result[j]);
        }
        return result;
    }
};
