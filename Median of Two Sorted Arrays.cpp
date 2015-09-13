class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        const int l = m + n;
        int *n1 = nums1.data();    //use data() function to access memory array internally used in vector
        int *n2 = nums2.data();
        //indexing of k. k shall be indexed starting from 1 and such indexing consistency shall be kept throughout the program
        if (l % 2 == 1) return findKth(n1, m, n2, n, l / 2 + 1);   
        else return (findKth(n1, m, n2, n, l / 2) + findKth(n1, m, n2, n, l / 2 + 1)) / 2.0;
    }

private:
    int findKth(int *nums1, int m, int *nums2, int n, int k){
        if (m > n) return findKth(nums2, n, nums1, m, k);
        if (m == 0) return nums2[k - 1];
        if (k == 1) return min(nums1[0], nums2[0]);  //A termination case
        int a = min(m, k / 2);
        int b = k - a;
        if (nums1[a - 1] == nums2[b - 1]) return nums1[a - 1];
        else if (nums1[a - 1] < nums2[b - 1]){
            return findKth(nums1 + a, m - a, nums2, n, k - a);
        }
        else{
            return findKth(nums1, m, nums2 + b, n - b, k - b);
        }
    }
};
