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
    int helper(TreeNode *rootIn, int numberIn) {
        int tmp = 0;
        
        if (!rootIn->right && !rootIn->left) {
            return 10 * numberIn + rootIn->val;
        }

        if (rootIn->left) {
            tmp += helper(rootIn->left, 10 * numberIn + rootIn->val);
        }
        
        if (rootIn->right) {
            tmp += helper(rootIn->right, 10 * numberIn + rootIn->val);
        }
        
        return tmp;
    }
};
