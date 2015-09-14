class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        if (height.empty()) return result;
        const int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        int lmax = height[0];
        for (int i = 1; i < n; ++i){
            left[i] = lmax;
            lmax = max(lmax, height[i]);
        }
        int rmax = height[n - 1];
        for (int i = n - 2; i >= 0; --i){
            right[i] = rmax;
            rmax = max(rmax, height[i]);
        }
        
        for (int i = 1; i < n - 1; ++i){
            int tmp = min(left[i], right[i]) - height[i];
            if (tmp > 0) result += tmp;
        }
        return result;
    }
};
