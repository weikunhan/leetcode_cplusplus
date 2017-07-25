//==============================================================================
// 110. Balanced Binary Tree
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/balanced-binary-tree/#/description

class Solution {
public:  
    bool isBalanced(TreeNode* root) {
        bool res = false;
        
        return res = helper(root) != -1;
    }

private:
    int helper(TreeNode *rootIn) {
        if (!rootIn) {
            return 0;
        }
        
        int leftHeight = helper(rootIn->left);
        
        if (leftHeight == -1) {
            return -1;
        }
        
        int rightHeight = helper(rootIn->right);
        
        if (rightHeight == -1) {
            return -1;
        }
        
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        
        return max(leftHeight, rightHeight) + 1;
    }
