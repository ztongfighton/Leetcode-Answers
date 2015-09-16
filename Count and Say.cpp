class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "";
        string result = "1";
        string next = "";
        for (int i = 2; i <= n; ++i){
            const int len = result.size();
            for (int j = 0; j < len;){
                char c = result[j];
                int count = 0;
                while (j < len && result[j] == c){
                    ++count;
                    ++j;
                }
                next.append(1, '0' + count);
                next.append(1, c);
            }
            swap(result, next);
            next.clear();
        }
        return result;
    }
};
