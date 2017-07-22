//==============================================================================
// 94. Binary Tree Inorder Traversal
// C++
// Tag: Stack, without Hash Table
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
        stack<TreeNode *> nodes;
        TreeNode *current = root;
        
        while (!nodes.empty() || current) {
            if (current) {
                nodes.push(current);
                current = current->left;
            } else {
                TreeNode *currentNode = nodes.top();
                res.push_back(currentNode->val);
                nodes.pop();
                current = currentNode->right;
            }
        }
        
        return res;
    }
};
