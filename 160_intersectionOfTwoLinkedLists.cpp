//==============================================================================
// 160. Intersection of Two Linked Lists
// C++
// Tag: Linked List
//==============================================================================
// Summary:
// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currentNode1 = headA;
        ListNode *currentNode2 = headB;
        
        while (currentNode1 != currentNode2) {
            currentNode1 = currentNode1 ? currentNode1->next:headB;
            currentNode2 = currentNode2 ? currentNode2->next:headA;
        }
        
        return currentNode1;
    }
};
