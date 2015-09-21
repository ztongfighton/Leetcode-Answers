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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> result;
        result = generate(1, n);
        return result;
    }
    
private:
    vector<TreeNode*> generate(int start, int end){
        vector<TreeNode*> result;
        if (start > end) result.push_back(nullptr);
        else if (start == end) {
            auto node = new TreeNode(start);
            result.push_back(node);
        }
        else{
            for (int i = start; i <= end; ++i){
                auto leftTrees = generate(start, i - 1);
                auto rightTrees = generate(i + 1, end);
                for (int j = 0; j < leftTrees.size(); ++j){
                    for (int k = 0; k < rightTrees.size(); ++k){
                        auto node = new TreeNode(i);
                        node -> left = leftTrees[j];
                        node -> right = rightTrees[k];
                        result.push_back(node);
                    }
                }
            }
        }
        return result;
    }
};
