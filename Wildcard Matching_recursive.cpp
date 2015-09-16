//This is the recursive version
class Solution {
public:
    bool isMatch(string s, string p) {
        const char *str = s.data();
        const char *ptr = p.data();
        return isMatch(str, ptr);
    }
    
private:
    bool isMatch(const char *s, const char *p){
        if (*p == '\0' || *s == '\0') return *p == *s;
        else if (*p == '*'){
            while (*p == '*') ++p;
            if (*p == '\0') return true;
            while (s != '\0' && !isMatch(s, p)){
                ++s
            }
            return *s != '\0';
        }
        else if (*p == '?' || *p == *s) return isMatch(++s, ++p);
        else return false;
    }
};
