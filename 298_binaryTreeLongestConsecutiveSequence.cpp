//==============================================================================
// 298. Binary Tree Longest Consecutive Sequence
// C++
// Tag: Tree
//==============================================================================
// Summary:
// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/

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
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        
        if (!root) {
            return res;
        }
        
        helper(root, 0, root->val, res);
        
        return res;
    }

private:
    void helper(TreeNode *rootIn, int targetIn, int stepIn, int &res) {
        if (!rootIn) {
            return;
        }
        
        if (rootIn->val == stepIn) {
            ++targetIn;
        } else {
            targetIn = 1;
        }
        
        res = max(targetIn, res);
        helper(rootIn->left, targetIn, rootIn->val + 1, res);
        helper(rootIn->right, targetIn, rootIn->val + 1, res);
    }
};
