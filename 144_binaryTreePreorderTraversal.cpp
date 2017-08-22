//==============================================================================
// 144. Binary Tree Preorder Traversal
// C++
// Tag: Tree(Stack)
//==============================================================================
// Summary:
// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> tables;
        
        if (!root) {
            return res;
        } else {
            tables.push(root);
        }
        
        while (!tables.empty()) {
            TreeNode *tmp = tables.top();
            res.push_back(tmp->val);
            tables.pop();
            if (tmp->right) {
                tables.push(tmp->right);
            }
            if (tmp->left) {
                tables.push(tmp->left);
            }
        }
        
        return res;
    }
};
