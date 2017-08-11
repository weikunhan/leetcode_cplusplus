//==============================================================================
// 226. Invert Binary Tree
// C++
// Tag: Tree(without Binary Search)
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
        
        TreeNode *left = rootIn->left;
        TreeNode *right = rootIn->right;
        rootIn->left = helper(right);
        rootIn->right = helper(left);
        
        return rootIn;
    }
};
