class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();
        if (n < 3) return n;
        int cur = 1;
        for (int i = 2; i < n; ++i){
            if (nums[i] != nums[cur - 1])
                nums[++cur] = nums[i];
        }
        return cur + 1;
    }
};
