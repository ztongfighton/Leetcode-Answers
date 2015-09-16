class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int result = 0;
        auto i = s.begin();
        while (*i == ' ') ++i;
        --i;
        for (; i != s.end();){
            ++i;
            auto j = find(i, s.end(), ' ');
            int len = distance(i, j);
            if (len > 0) result = len;
            i = j;
        }
        return result;
    }
};
