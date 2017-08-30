//==============================================================================
// 236. Lowest Common Ancestor of a Binary Tree
// C++
// Tag: Tree
//==============================================================================
// Summary:
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *res;
        
        return res = helper(root, p, q);
    }
    
private:
    TreeNode *helper(TreeNode *rootIn, TreeNode *minIn, TreeNode *maxIn) {
        if (rootIn == minIn || rootIn == maxIn || !rootIn) {
            return rootIn;
        }
        
        TreeNode *leftRoot = helper(rootIn->left, minIn, maxIn);
        TreeNode *rightRoot = helper(rootIn->right, minIn, maxIn);
        
        if (!leftRoot) {
            return rightRoot;
        } else if (!rightRoot) {
            return leftRoot;
        } else {
            return rootIn;
        }
    }
};
