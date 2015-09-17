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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode *cur = root, *prev = nullptr;
        stack<TreeNode *> stk;
        do{
            while (cur != nullptr){
                stk.push(cur);
                cur = cur -> left;
            }
            
            while (!stk.empty()){
                cur = stk.top();
                stk.pop();
                if (cur -> right != nullptr && cur -> right != prev){
                    stk.push(cur);
                    cur = cur -> right;
                    break;
                }
                else {
                    result.push_back(cur -> val);
                    prev = cur;
                }
            }
            
        }while (!stk.empty());
        return result;
    }
};
