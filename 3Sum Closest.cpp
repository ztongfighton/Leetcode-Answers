class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = INT_MAX;
        int result = 0;
        const int n = nums.size();
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
                if (sum == target) return target;
                else {
                    int diff = abs(sum - target);
                    if (diff < min_diff){
                        min_diff = diff;
                        result = sum;
                    }
                    if (sum < target) ++j;
                    else --k;
                }
            }
        }
        return result;
    }
};
