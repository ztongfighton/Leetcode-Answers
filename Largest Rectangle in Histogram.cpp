class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        if (height.empty()) return 0;
        const int n = height.size();
        stack<int> stk;
        int result = 0;
        stk.push(0);
        for (int i = 1; i < n; ++i){
            if (stk.empty() || height[i] >= height[stk.top()])
                stk.push(i);
            else{
                while (!stk.empty() && height[i] < height[stk.top()]){
                    int h = height[stk.top()];
                    stk.pop();
                    if (stk.empty()) result = max(result, h * i);
                    else result = max(result, h * (i - stk.top() - 1));
                }
                stk.push(i);
            }
        }
        
        while (!stk.empty()){
            int h = height[stk.top()];
            stk.pop();
            if (!stk.empty())
                result = max(result, h * (n - stk.top()- 1));
            else
                result = max(result, h * n);
        }
        return result;
    }
};
