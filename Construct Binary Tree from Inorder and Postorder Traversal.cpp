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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    
private:
    template<class InputIterator>
    TreeNode* buildTree(InputIterator in_first, InputIterator in_last, InputIterator post_first, InputIterator post_last){
        if (in_first == in_last || post_first == post_last) return nullptr;
        const int val = *prev(post_last);
        TreeNode *root = new TreeNode(val);
        auto mid = find(in_first, in_last, val);
        auto leftTreeSize = distance(in_first, mid);
        root -> left = buildTree(in_first, mid, post_first, post_first + leftTreeSize);
        root -> right = buildTree(next(mid), in_last, post_first + leftTreeSize, prev(post_last));
        return root;
    }
};
