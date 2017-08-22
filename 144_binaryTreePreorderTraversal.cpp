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
        TreeNode *currentRoot = root;
        
        while(!tables.empty() || current) {
            if (currentRoot) {
                tables.push(currentRoot);
                res.push_back(currentRoot->val);
                currentRoot = currentRoot->left;
            } else {
                TreeNode *tmp = tables.top();
                tables.pop();
                currentRoot = tmp->right;   
            }
        }
        
        return res;
    }
};
