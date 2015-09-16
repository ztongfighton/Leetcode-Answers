class Solution {
public:
    bool isNumber(string s) {
        const char *str = s.data();
        char *endptr;
        strtod(str, &endptr);
        if (endptr == str) return false;
        
        for (; *endptr; ++endptr){
            if (!isspace(*endptr)) return false;
        }
        
        return true;
    }
};
