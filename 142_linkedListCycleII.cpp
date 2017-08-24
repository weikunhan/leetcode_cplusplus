//==============================================================================
// 142. Linked List Cycle II
// C++
// Tag: Linked List(2 Pointers)
//==============================================================================
// Summary:
// https://leetcode.com/problems/linked-list-cycle-ii/description/

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *res = head;
        ListNode *left  = head;
        ListNode *right  = head;
        
        if (!head || !head->next) {
            return NULL;
        }
        
        while (right->next && right->next->next) {
            left = left->next;
            right = right->next->next;
            if (left == right) {
                while (left != res) {
                    left  = left->next;
                    res = res->next;
                }
                return res;
            }
        }
        
        return NULL;
    }
};
