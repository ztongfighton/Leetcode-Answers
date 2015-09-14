class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> prev;
        prev.push_back(0);
        if (n < 1) return prev;
        vector<int> cur;
        prev.push_back(1);
        for (int i = 2; i <= n; ++i){
            bool flag = true;
            for (int j = 0; j < prev.size(); ++j){
                if(flag){
                    cur.push_back(prev[j] * 2);
                    cur.push_back(prev[j] * 2 + 1);
                }
                else{
                    cur.push_back(prev[j] * 2 + 1);
                    cur.push_back(prev[j] * 2);
                }
                flag = !flag;
            }
            swap(cur, prev);
            cur.clear();
        }
        return prev;
    }
};
