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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        vector<TreeNode *> cur, next;
        cur.push_back(root);
        while (!cur.empty()){
            vector<int> level;
            for (int i = 0; i < cur.size(); ++i){
                level.push_back(cur[i] -> val);
                if (cur[i] -> left != nullptr) next.push_back(cur[i] -> left);
                if (cur[i] -> right != nullptr) next.push_back(cur[i] -> right);
            }
            result.push_back(level);
            swap(cur, next);
            next.clear();
        }
        return result;
    }
};
