//==============================================================================
// 100. Same Tree
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/same-tree/#/description

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res = false;
    
        return res = helper(p, q);
    }
    
private:
    bool helper(TreeNode* rootIn1, TreeNode* rootIn2) {
        if (!rootIn1 || !rootIn2) {
            return rootIn1 == rootIn2;
        }
        
        if (rootIn1->val != rootIn2->val) {
            return false;
        }
    
        return helper(rootIn1->left, rootIn2->left) && helper(rootIn1->right, rootIn2->right);
    }
};
