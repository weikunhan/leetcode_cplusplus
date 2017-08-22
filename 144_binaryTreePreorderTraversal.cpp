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
        TreeNode *current = root;
        
        while(!tables.empty() || current) {
            if (current) {
                tables.push(current);
                res.push_back(current->val);
                current = current->left;
            } else {
                TreeNode *tmp = tables.top();
                tables.pop();
                current = tmp->right;   
            }
        }
        
        return res;
    }
};
