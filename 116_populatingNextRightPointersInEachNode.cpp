//==============================================================================
// 116. Populating Next Right Pointers in Each Node
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/tabs/description

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        
        TreeLinkNode *current = root;
        
        while (current->left) {
            TreeLinkNode *currentNode = current;
            while (currentNode) {
                currentNode->left->next = currentNode->right;
                if (currentNode->next) {
                    currentNode->right->next = currentNode->next->left;
                }
                currentNode = currentNode->next;
            }
            current = current->left;
        }
    }
};
