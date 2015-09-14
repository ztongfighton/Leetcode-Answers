class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return nums[0];
        int result = nums[0];
        for (int i = 1; i < n; ++i){
            result ^= nums[i];
        }
        return result;
    }
};
