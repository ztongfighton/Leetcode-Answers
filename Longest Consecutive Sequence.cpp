class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_map<int, bool> used;
        for (int i = 0; i < nums.size(); ++i)
            used[nums[i]] = false;
        
        for (int i = 0; i < nums.size(); ++i){
            if (used[nums[i]]) continue;
            int length = 1;
            used[nums[i]] = true;
            for (int j = nums[i] + 1; used.find(j) != used.end(); ++j){
                ++length;
                used[j] = true;
            }
            
            for (int j = nums[i] - 1; used.find(j) != used.end(); --j){
                ++length;
                used[j] = true;
            }
            longest = max(longest, length);
        }
        
        return longest;
    }
};
