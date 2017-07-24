//==============================================================================
// 105. Construct Binary Tree from Preorder and Inorder Traversal
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/#/description

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* res = NULL;
        
        return res = helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& preorderIn, vector<int>& inorderIn, int minIn1, int maxIn1, int minIn2, int maxIn2) {
        int index = 0;
        
        if (minIn1 > maxIn1) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorderIn[minIn1]);
    
        for (int i = minIn2; i <= maxIn2; ++i) {
            if (inorderIn[i] == root->val) {
                index = i;
                break;
            }
        }
    
        root->left = helper(preorderIn, inorderIn, minIn1 + 1, minIn1 + index - minIn2, minIn2, index - 1);
        root->right = helper(preorderIn, inorderIn, maxIn1 - maxIn2 + index + 1, maxIn1, index + 1, maxIn2);
        
        return root;
    }
};
