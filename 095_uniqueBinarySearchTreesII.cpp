//==============================================================================
// 95. Unique Binary Search Trees II
// C++
// Tag: Tree(without DP)
//==============================================================================
// Summary:
// https://leetcode.com/problems/unique-binary-search-trees-ii/#/description

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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> res;
        
        if (n == 0) {
            return res;
        }
        
        return res = helper(1, n);
    }
    
private:
    vector<TreeNode *> helper(int minIn, int maxIn) {
        vector<TreeNode *> tmp;
        
        if (minIn > maxIn) {
            tmp.push_back(NULL);
            return tmp;
        }
        
        for (int i = minIn; i <= maxIn; ++i) {
            vector<TreeNode *> leftSubTree = helper(minIn, i - 1);
            vector<TreeNode *> rightSubTree = helper(i + 1, maxIn);
            for (int j = 0; j < leftSubTree.size(); ++j) {
                for (int k = 0; k < rightSubTree.size(); ++k) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftSubTree[j];
                    root->right = rightSubTree[k];
                    tmp.push_back(root);
                }
            }
        }
        
        return tmp;
    }
};
