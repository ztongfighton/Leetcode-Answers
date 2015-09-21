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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    
private:
    template<class InputIterator>
    TreeNode* buildTree(InputIterator pre_first, InputIterator pre_last, InputIterator in_first, InputIterator in_last){
        if (pre_first == pre_last || in_first == in_last) return nullptr;
        const int val = *pre_first;
        TreeNode *root = new TreeNode(val);
        auto mid = find(in_first, in_last, val);
        auto leftTreeSize = distance(in_first, mid);
        root -> left = buildTree(next(pre_first), next(pre_first, 1 + leftTreeSize), in_first, mid);
        root -> right = buildTree(next(pre_first, 1 + leftTreeSize), pre_last, next(mid), in_last);
        return root;
        
    }
};
