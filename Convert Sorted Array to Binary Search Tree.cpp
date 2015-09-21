/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums.begin(), nums.end());
    }

private:
    template<class randomAccessIterator>
    TreeNode* sortedArrayToBST(randomAccessIterator first, randomAccessIterator last){
        if (first >= last) return nullptr;
        auto mid = first + distance(first, last) / 2;
        TreeNode *root = new TreeNode(*mid);
        root -> left = sortedArrayToBST(first, mid);
        root -> right = sortedArrayToBST(next(mid), last);
        return root;
    }
};
