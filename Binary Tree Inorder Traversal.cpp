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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        TreeNode *cur = root;
        while (cur != nullptr){
            if (cur -> left == nullptr){
                result.push_back(cur -> val);
                cur = cur -> right;
            }
            else{
                TreeNode *prev = cur -> left;
                while (prev -> right != nullptr && prev -> right != cur)
                    prev = prev -> right;
                if (prev -> right == nullptr){
                    prev -> right = cur;
                    cur = cur -> left;
                }
                else{
                    prev -> right = nullptr;
                    result.push_back(cur -> val);
                    cur = cur -> right;
                }
            }
        }
        return result;
    }
};
