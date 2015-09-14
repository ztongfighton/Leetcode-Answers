class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        const int n = ratings.size();
        vector<int> extra(n, 0);
        
        int lmax = 0;
        for (int i = 1; i < n; ++i){
            if (ratings[i] > ratings[i - 1]){
                extra[i] = max(extra[i], ++lmax);
            }
            else lmax = 0;
        }
        
        int rmax = 0;
        for (int i = n - 2; i >= 0; --i){
            if (ratings[i] > ratings[i + 1]){
                extra[i] = max(extra[i], ++rmax);
            }
            else rmax = 0;
        }
        
        int result = n;
        for (int i = 0; i < n; ++i)
            result += extra[i];
            
        return result;
    }
};
