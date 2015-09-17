/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) return;
        TreeLinkNode *cur = root;
        TreeLinkNode *next = nullptr, *prev = nullptr;
        while (cur != nullptr){
            while (cur != nullptr){
                if (cur -> left != nullptr){
                    if (next == nullptr) next = cur -> left;
                    if (prev != nullptr) {
                        prev -> next = cur -> left;
                        prev = cur -> left;
                    }
                    else prev = cur -> left;
                }
                
                if (cur -> right != nullptr){
                    if (next == nullptr) next = cur -> right;
                    if (prev != nullptr){
                        prev -> next = cur -> right;
                        prev = cur -> right;
                    }
                    else prev = cur -> right;
                }
                
                cur = cur -> next;
            }
            cur = next;
            next = nullptr;
            prev = nullptr;
        }
    }
};
