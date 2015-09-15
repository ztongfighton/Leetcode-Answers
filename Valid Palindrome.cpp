class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        const int n = s.size();
        if (n == 1) return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto left = s.begin(), right = prev(s.end());
        while (left < right){
            if(!::isalnum(*left)) ++left;
            else if(!::isalnum(*right)) --right;
            else if (*left != *right) return false;
            else{
                ++left;
                --right;
            }
        }
        return true;
    }
};
