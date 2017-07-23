//==============================================================================
// 101. Symmetric Tree
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/symmetric-tree/#/description

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
    bool isSymmetric(TreeNode* root) {
        bool res = false;
        
        if (!root) {
            return res = true;
        }
        
        return res = helper(root->left, root->right);
    }

private:
    bool helper(TreeNode* rootIn1, TreeNode* rootIn2) {
        if (!rootIn1 || !rootIn2) {
            return rootIn1 == rootIn2;
        }
        
        if (rootIn1->val != rootIn2->val) {
            return false;
        }
        
        return helper(rootIn1->left, rootIn2->right) && helper(rootIn1->right, rootIn2->left);
    }
};
