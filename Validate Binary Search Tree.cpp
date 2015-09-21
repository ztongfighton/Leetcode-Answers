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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MAX, INT_MIN);
    }
    
private:
    bool isValidBST(TreeNode* root, int upperbound, int lowerbound){
        if (root == nullptr) return true;
        if (root -> val >= upperbound || root -> val <= lowerbound) return false;
        return isValidBST(root -> left, min(root -> val, upperbound), lowerbound) && 
        isValidBST(root -> right, upperbound, max(root -> val, lowerbound));
    }
};
