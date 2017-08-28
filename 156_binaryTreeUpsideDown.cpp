//==============================================================================
// 156. Binary Tree Upside Down
// C++
// Tag: Tree
//==============================================================================
// Summary:
// https://leetcode.com/problems/binary-tree-upside-down/description/

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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode *currentRoot = root;
        
        if (!currentRoot || !currentRoot->left) {
            return currentRoot;
        }
        
        TreeNode *leftRoot = currentRoot->left;
        TreeNode *rightRoot = currentRoot->right;
        TreeNode* newRoot = upsideDownBinaryTree(currentRoot->left);
        leftRoot->right = currentRoot;
        leftRoot->left = rightRoot;
        currentRoot->left = NULL;
        currentRoot->right = NULL;
        
        return newRoot;
    }
};
