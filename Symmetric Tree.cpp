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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        stack<TreeNode*> stk;
        stk.push(root -> left);
        stk.push(root -> right);
        while (!stk.empty()){
            auto p = stk.top(); stk.pop();
            auto q = stk.top(); stk.pop();
            if (p == nullptr && q == nullptr) continue;
            else if (p == nullptr || q == nullptr) return false;
            else {
                if(p -> val != q -> val) return false;
                stk.push(p -> left);
                stk.push(q -> right);
                stk.push(p -> right);
                stk.push(q -> left);
            }
        }
        return true;
    }
};
