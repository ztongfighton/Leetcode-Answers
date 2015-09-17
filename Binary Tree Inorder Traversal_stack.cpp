/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//This is the stack version
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode *p = root;
        stack<TreeNode *> stk;
        while (p != nullptr || !stk.empty()){
            if (p != nullptr){
                stk.push(p);
                p = p -> left;
            }
            else{
                p = stk.top();
                stk.pop();
                result.push_back(p -> val);
                p = p -> right;
            }
        }
        return result;
    }
};
