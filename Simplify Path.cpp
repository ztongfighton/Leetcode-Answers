class Solution {
public:
    string simplifyPath(string path) {
        string result;
        if (path.empty()) return result;
        vector<string> subpath;
        const int n = path.size();
        for (auto i = path.begin(); i != path.end();){
            ++i;
            auto j = find(i, path.end(), '/');
            string ss = string(i, j);
            if (ss == ".."){
                if (!subpath.empty()) subpath.pop_back();
            }
            else if (!ss.empty() && ss != ".")
                subpath.push_back(ss);
            i = j;
        }
        
        if (subpath.empty()) return "/";
        for (int i = 0; i < subpath.size(); ++i){
            result += '/';
            result += subpath[i];
        }
        return result;
    }
};
