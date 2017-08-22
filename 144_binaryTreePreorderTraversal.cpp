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
        
        while(!tables.empty() || root) {
            if (root) {
                tables.push(root);
                res.push_back(root->val);
                root = root->left;
            } else {
                TreeNode *tmp = tables.top();
                tables.pop();
                root = tmp->right;   
            }
        }
        
        return res;
    }
};
