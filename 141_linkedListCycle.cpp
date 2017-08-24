//==============================================================================
// 141. Linked List Cycle
// C++
// Tag: Linked List(2 Pointers)
//==============================================================================
// Summary:
// https://leetcode.com/problems/linked-list-cycle/description/

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
    bool hasCycle(ListNode *head) {
        ListNode *left = head;
        ListNode *right = head;
        bool res = false;
        
        if (!head || !head->next) {
            return res;
        }
 
        while (right->next && right->next->next) {
            left = left->next;
            right = right->next->next;
            if (left == right) {
                return res = true;
            }
        }
 
        return res;
    }
};
