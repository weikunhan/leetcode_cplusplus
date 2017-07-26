//==============================================================================
// 114. Flatten Binary Tree to Linked List
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/#/description

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
    void flatten(TreeNode* root) {
        helper(root);
    }
    
private:
    void helper(TreeNode *rootIn) {
        TreeNode *current = rootIn;
        
        if (!rootIn) {
            return;
        }
         
        TreeNode *left = rootIn->left;
        TreeNode *right = rootIn->right;
        helper(right);
        helper(left);
        rootIn->left = NULL;
        rootIn->right = left;

        while (current->right) {
            current = current->right;
        }
        
        current->right = right;
    }
};
