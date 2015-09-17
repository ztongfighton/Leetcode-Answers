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
    void recoverTree(TreeNode* root) {
        if (root == nullptr) return;
        TreeNode *cur = root, *prev = nullptr;
        pair<TreeNode* , TreeNode*> broken;
        while (cur != nullptr){
            if (cur -> left == nullptr){
                detect(broken, prev, cur);
                prev = cur;
                cur = cur -> right;
    
            }
            else{
                TreeNode *node = cur -> left;
                while (node -> right != nullptr && node -> right != cur)
                    node = node -> right;
                if (node -> right == nullptr){
                    node -> right = cur;
                    cur = cur -> left;
                }
                else{
                    node -> right = nullptr;
                    detect(broken, prev, cur);
                    prev = cur;
                    cur = cur -> right;
    
                }
            }
        }
        swap(broken.first -> val, broken.second -> val);
    }
    
private:
    void detect(pair<TreeNode*, TreeNode*>& broken, TreeNode* prev, TreeNode* cur){
        if (prev != nullptr && prev -> val > cur -> val){
            if (broken.first == nullptr) 
                broken.first = prev;
        broken.second = cur;
        }
    }
};
