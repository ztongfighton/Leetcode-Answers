class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        const int n = nums.size();
        if (n < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int a = nums[i];
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int b = nums[j];
                int c = nums[k];
                int sum = a + b + c;
                if (sum == 0){
                    int tmp[3] = {a, b, c};
                    result.push_back(vector<int>(tmp, tmp + 3));
                    j = j + 1;
                    while (nums[j] == nums[j - 1]) ++j;
                    k = k - 1;
                    while (nums[k] == nums[k + 1]) --k;
                }
                else if (sum < 0){
                    ++j;
                }
                else
                    --k;
            }
        }
        return result;
    }
};
