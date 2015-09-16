//This is the iterative version
class Solution {
public:
    bool isMatch(string s, string p) {
        string::iterator str1, ptr1, str2, ptr2;
        bool star = false;
        for (str1 = s.begin(), ptr1 = p.begin(); str1 != s.end(); ++str1, ++ptr1){
            switch (*ptr1){
                case '?':
                    break;
                case '*':
                    star = true;
                    str2 = str1;
                    ptr2 = ptr1;
                    while (ptr2 != p.end() && *ptr2 == '*') ++ptr2;
                    if (ptr2 == p.end()) return true;
                    str1 = str2 - 1;
                    ptr1 = ptr2 - 1;
                    break;
                default:
                    if (*str1 != *ptr1){
                        if (star){
                            ++str2;
                            str1 = str2 - 1;
                            ptr1 = ptr2 - 1;
                        }
                        else return false;
                    }
            }
        } 
        
        while (ptr1 != p.end() && *ptr1 == '*') ++ptr1;
        return ptr1 == p.end();
    }
};
