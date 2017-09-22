//==============================================================================
// 270. Closest Binary Search Tree Value
// C++
// Tag: Tree(without Binary Search)
//==============================================================================
// Summary:
// https://leetcode.com/problems/closest-binary-search-tree-value/description/

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
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        
        while (root) {
            if (abs(res - target) >= abs(root->val - target)) {
                res = root->val;
            }
            root = (target < root->val) ? root->left:root->right;
        }
        
        return res;
    }
};
