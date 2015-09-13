class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        const int n = nums.size();
        if (n < 4) return result;
        unordered_map<int, vector<pair<int, int>>> table;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; ++i){
            for (int j = i + 1; j < n; ++j){
                table[nums[i] + nums[j]].push_back(pair<int, int>(i, j));
            }
        }
        
        for (auto i = table.begin(); i != table.end(); ++i){
            int gap = target - i -> first;
            auto j = table.find(gap);
            if (j != table.end()){
                for (auto m : i -> second){
                    for (auto n : j -> second){
                        int a = m.first, b = m.second, c = n.first, d = n.second;
                        if (a < b && b < c && c < d)
                            result.push_back(vector<int>{nums[a], nums[b], nums[c], nums[d]});
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
