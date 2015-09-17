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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        queue<TreeNode*> current, next;
        vector<int> level;
        current.push(root);
        while (!current.empty()){
            while (!current.empty()){
                TreeNode *node = current.front();
                current.pop();
                level.push_back(node -> val);
                if (node -> left != nullptr) next.push(node -> left);
                if (node -> right != nullptr) next.push(node -> right);
            }
            result.push_back(level);
            level.clear();
            swap(current, next);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
