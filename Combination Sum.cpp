class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.empty()) return result;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(result, path, candidates, target, 0);
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& result, vector<int>& path, vector<int>& candidates, int target, int start){
        if (target == 0){
            result.push_back(path);
            return;
        }
        
        const int n = candidates.size();
        for (int i = start; i < n; ++i){
            if (candidates[i] > target) break;
            path.push_back(candidates[i]);
            dfs(result, path, candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
    
};
