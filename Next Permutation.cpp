class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int>::reverse_iterator rfirst = nums.rbegin();
        vector<int>::reverse_iterator rlast = nums.rend();
        auto pivot = next(rfirst);
        while (*pivot >= *prev(pivot) && pivot != rlast)
            pivot = next(pivot);
        if (pivot == rlast)
            reverse(nums.begin(), nums.end());
        else{
            auto change = rfirst;
            while (*change <= *pivot && change != pivot)
                change = next(change);
            
            swap(*pivot, *change);
            reverse(rfirst, pivot);
        }
    }
};
