//==============================================================================
// 117. Populating Next Right Pointers in Each Node II
// C++
// Tag: Tree(DFS)
//==============================================================================
// Summary:
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/tabs/description

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
        TreeLinkNode *tmp = new TreeLinkNode(0);
        TreeLinkNode *current = root;
        
        while (current) {
            TreeLinkNode *currentNode = tmp;
            while (current) {
                if (current->left) { 
                    currentNode->next = current->left;
                    currentNode = currentNode->next;
                }
                if (current->right) { 
                    currentNode->next = current->right; 
                    currentNode = currentNode->next;
                }
                current = current->next;
            }
            current = tmp->next;
            tmp->next = NULL;
        }
    }
};
