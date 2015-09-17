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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        if (root -> left == nullptr && root -> right == nullptr) return;
        flatten(root -> left);
        flatten(root -> right);
        if (root -> left != nullptr){
            TreeNode *prev = root -> left;
            while (prev -> right != nullptr)
                prev = prev -> right;
            
            auto rightTree = root -> right;
            root -> right = root -> left;
            root -> left = nullptr;
            prev -> right = rightTree;
        }
    }
};
