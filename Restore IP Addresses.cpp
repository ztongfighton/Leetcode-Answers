class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        const int n = s.size();
        if (n == 0) return result;
        vector<string> path;
        dfs(result, path, s, 0, 0, n);
        return result;
    }
    
private:
    void dfs(vector<string>& result, vector<string>& path, string& s, int order, int start, int end){
        if (start == end && order == 4){
            string ip;
            for (int i = 0; i < 4; ++i){
                ip += path[i] + ".";
            }
            result.push_back(ip.substr(0, ip.size() - 1));
            return;
        }
        
        if (end - start > 3 * (4 - order)) return;
        int num = 0;
        for (int i = start; i < start + 3 && i < end; ++i){
                num = 10 * num + s[i] - '0';
                if (num >= 0 && num <= 255){
                    path.push_back(s.substr(start, i - start + 1));
                    dfs(result, path, s, order + 1, i + 1, end);
                    path.pop_back();
                }
                if (num == 0) break;
        }
    }
};
