//==============================================================================
// 129. Sum Root to Leaf Numbers
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        
        if (!root) {
            return res;
        }
        
        return res = helper(root, 0);
    }

private:
    int helper(TreeNode *root, int numberIn) {
        int tmp = 0;
        
        if (!root->right && !root->left) {
            return 10 * numberIn + root->val;
        }

        if (root->left) {
            tmp += helper(root->left, 10 * numberIn + root->val);
        }
        
        if (root->right) {
            tmp += helper(root->right, 10 * numberIn + root->val);
        }
        
        return tmp;
    }
};
