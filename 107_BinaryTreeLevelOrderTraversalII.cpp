//==============================================================================
// 107. Binary Tree Level Order Traversal II
// C++
// Tag: Tree(BFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/#/description

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
        vector<vector<int>> res;
        queue<TreeNode *> nodes;
        
        if (!root) {
            return res;
        } else {
            nodes.push(root);
        }
        
        while (!nodes.empty()) {
            int levelSize = nodes.size();
            vector<int> tmp;
            for (int i = 0; i < levelSize; ++i) {
                if (nodes.front()->left) {
                    nodes.push(nodes.front()->left);
                }
                if (nodes.front()->right) {
                    nodes.push(nodes.front()->right);
                }
                tmp.push_back(nodes.front()->val);
                nodes.pop();
            }
            res.push_back(tmp);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
