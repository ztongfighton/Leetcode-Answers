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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == nullptr || q == nullptr) return nullptr;
        if (root == p || root == q) return root;
        vector<TreeNode*> ppath, qpath;
        bool findp = getPath(root, p, ppath);
        bool findq = getPath(root, q, qpath);
        if (!findp || !findq) return nullptr;
        auto piter = ppath.begin(), qiter = qpath.begin();
        TreeNode* ancestor;
        while (piter != ppath.end() && qiter != qpath.end() && *piter == *qiter){
            ancestor = *piter;
            ++piter;
            ++qiter;
        }
        return ancestor;
    }
private:
    bool getPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path){
        if (root == nullptr || p == nullptr) return false;
        path.push_back(root);
        if (root == p) return true;
        else{
            if (getPath(root -> left, p, path))
                return true;
            else if (getPath(root -> right, p, path))
                return true;
            else{
                path.pop_back();
                return false;
            }
        }
    }

};
