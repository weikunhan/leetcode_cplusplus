//==============================================================================
// 94. Binary Tree Inorder Traversal
// C++
// Tag: Tree(Stack, without Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/binary-tree-inorder-traversal/#/description

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
        vector<int> res;
        stack<TreeNode *> tables;
        TreeNode *currentRoot = root;
        
        while (!tables.empty() || currentRoot) {
            if (currentRoot) {
                tables.push(currentRoot);
                currentRoot = currentRoot->left;
            } else {
                TreeNode *tmp = tables.top();
                res.push_back(tmp->val);
                tables.pop();
                currentRoot = tmp->right;
            }
        }
        
        return res;
    }
};
