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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()){
            auto node = stk.top(); 
            stk.pop();
            result.push_back(node -> val);
            if (node -> right != nullptr) stk.push(node -> right);
            if (node -> left != nullptr) stk.push(node -> left);
        }
        return result;
    }
};
