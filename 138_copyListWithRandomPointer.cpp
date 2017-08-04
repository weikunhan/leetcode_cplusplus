//==============================================================================
// 138. Copy List with Random Pointer
// C++
// Tag: Linked List(Hash table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/copy-list-with-random-pointer/description/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> tables;
        RandomListNode *res = new RandomListNode(0);
        RandomListNode *current = res;
        RandomListNode *currentNode = head;
     
        while (currentNode) {
            current->next = new RandomListNode(currentNode->label);
            tables[currentNode] = new RandomListNode(currentNode->label); 
            currentNode = currentNode->next;
            current = current->next;
        }
  
        currentNode = head;
        current = res->next;
        
        while (currentNode) {
            current->random = tables[currentNode->random];
            currentNode = currentNode->next;
            current = current->next;
        }
  
        return res->next;
    }
};
