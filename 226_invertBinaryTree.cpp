//==============================================================================
// 226. Invert Binary Tree
// C++
// Tag: Tree
//==============================================================================
// Summary:
// https://leetcode.com/problems/invert-binary-tree/description/

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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *res;

        return res = helper(root);
    }
    
private:
    TreeNode *helper(TreeNode *rootIn) {     
        if (!rootIn) {
            return NULL;
        }
        
        TreeNode *leftRoot = rootIn->left;
        TreeNode *rightRoot = rootIn->right;
        rootIn->left = helper(rightRoot);
        rootIn->right = helper(leftRoot);
        
        return rootIn;
    }
};
