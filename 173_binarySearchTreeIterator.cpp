//==============================================================================
// 173. Binary Search Tree Iterator
// C++
// Tag: Design, Tree(Stack)
//==============================================================================
// Summary:
// https://leetcode.com/problems/binary-search-tree-iterator/description/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        helper(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !tables.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmp = tables.top();
        tables.pop();
        helper(tmp->right);
        
        return tmp->val;
    }

private:
    stack<TreeNode *> tables;
    
    void helper(TreeNode *rootIn) {
        while (rootIn) {
            tables.push(rootIn);
            rootIn = rootIn->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
