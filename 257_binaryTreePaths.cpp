//==============================================================================
// 257. Binary Tree Paths
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/binary-tree-paths/description/

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        
        if (!root) {
            return res;
        }
    
        helper(root, to_string(root->val), res);
        
        return res;
    }

private:
    void helper(TreeNode *rootIn, string wordIn, vector<string> &res) {
        if (!rootIn->left && !rootIn->right) {
            res.push_back(wordIn);
            return;
        }

        if (rootIn->left) {
            helper(rootIn->left, wordIn + "->" + to_string(rootIn->left->val), res);
        }
        
        if (rootIn->right) {
            helper(rootIn->right, wordIn + "->" + to_string(rootIn->right->val), res);
        }
    }
};
