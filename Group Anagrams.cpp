class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.empty()) return result;
        const int n = strs.size();
        unordered_map<string, vector<string>> anagrams;
        for (int i = 0; i < n; ++i){
            string s = strs[i];
            sort(s.begin(), s.end());
            anagrams[s].push_back(strs[i]);
        }
        
        for (auto i = anagrams.begin(); i != anagrams.end(); ++i){
            sort(i -> second.begin(), i -> second.end());
            result.push_back(i -> second);
        }
        
        return result;
    }
};
