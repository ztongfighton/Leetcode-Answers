class Solution {
public:
    bool isMatch(string s, string p) {
        const char *str = s.data();
        const char *ptr = p.data();
        return isMatch(str, ptr);
    }
    
private:
    bool isMatch(const char *s, const char *p){
        if (*p == '\0') return *s == '\0';
        else if (*(p + 1) == '*'){
            while (((*p == '.' && *s != '\0') || *p == *s)){
                if (isMatch(s, p + 2)) return true;
                else ++s;
            }
            return isMatch(s, p + 2);
        }
        else{
            if ((*p == '.' && *s != '\0') || *p == *s) return isMatch(++s, ++p);
            else return false;
        }
    }
};
