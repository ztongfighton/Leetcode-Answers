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
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1 ? true : false;
    }
private:
    int getHeight(TreeNode* root){
        if (root == nullptr) return 0;
        if (root -> left == nullptr && root -> right == nullptr) return 1;
        int l = getHeight(root -> left);
        int r = getHeight(root -> right);
        if (l == -1 || r == -1) return -1;
        return abs(l - r) > 1 ? -1 : 1 + max(l, r);
    }
};
