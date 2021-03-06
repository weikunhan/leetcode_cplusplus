//==============================================================================
// 86. Partition List
// C++
// Tag: Linked List(2 Pointers)
//==============================================================================
// Summary:
// https://leetcode.com/problems/partition-list/#/description

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *res = new ListNode(0);
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);
        ListNode *currentLeft = left;
        ListNode *currentRight = right;
        ListNode *current = res;
        left->next = head;
        
        while (currentLeft->next) {
            if (currentLeft->next->val < x) {
                current->next = currentLeft->next; 
                current = current->next;
            } else {
                currentRight->next = currentLeft->next;
                currentRight = currentRight->next;
            }
            currentLeft = currentLeft->next;
        }
        
        currentRight->next = NULL;
        current->next = right->next;
        
        return res->next;
    }
};
