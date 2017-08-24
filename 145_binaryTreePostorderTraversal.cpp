//==============================================================================
// 145. Binary Tree Postorder Traversal
// C++
// Tag: Tree(Stack)
//==============================================================================
// Summary:
// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> tables;
        TreeNode *currentRoot = root;
        TreeNode *lastRoot = NULL;

        while (!tables.empty() || currentRoot ) {
            if (currentRoot) {
                tables.push(currentRoot);
                currentRoot = currentRoot->left;
            } else {
                TreeNode* tmp = tables.top();
                if (tmp->right && lastRoot != tmp->right) {
                    currentRoot = tmp->right;
                } else {
                    res.push_back(tmp->val);
                    tables.pop();
                    lastRoot = tmp; 
                }
            }
        }
        
        return res;
    }
};
