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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root -> left == nullptr && root -> right == nullptr) return 1;
        TreeNode* pleft = root -> left, *pright = root -> right;
        int height = 1;
        while(pleft && pright){
            pleft = pleft -> left;
            pright = pright -> right;
            ++height;
        }
        
        if (!pleft && !pright) return (1 << height) - 1;
        else return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};
