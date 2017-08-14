//==============================================================================
// 222. Count Complete Tree Nodes
// C++
// Tag: Tree(Binary Search)
//==============================================================================
// Summary:
// https://leetcode.com/problems/count-complete-tree-nodes/description/

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
    int countNodes(TreeNode* root) {
        int res = 0;
        
        int leftHigh = helper1(root);
        int rightHigh = helper2(root);     
            
        if (leftHigh == rightHigh) { 
            return res = pow(2, leftHigh) - 1;  
        }
        
        return res = countNodes(root->left) + countNodes(root->right) + 1;
    }

private:
    int helper1(TreeNode* rootIn) {
        if (!rootIn) {
            return 0;
        }
        
        return helper1(rootIn->left) + 1;
    }
                                
    int helper2(TreeNode* rootIn) {
        if (!rootIn) {
            return 0;
        }
        
        return helper2(rootIn->right) + 1;
    }
};
