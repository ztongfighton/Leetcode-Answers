class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, vector<int>> mapping;
        for (int i = 0; i < nums.size(); ++i)
            mapping[nums[i]].push_back(i + 1);
            
        for (auto i = mapping.begin(); i != mapping.end(); ++i){
            int gap = target - i->first;
            auto j = mapping.find(gap);
            if (j != mapping.end()){
                for (auto m : i->second){
                    for (auto n : j->second){
                        if (m < n){
                            result.push_back(m);
                            result.push_back(n);
                            return result;
                        }
                    }
                }
            }
        }
    }
};
