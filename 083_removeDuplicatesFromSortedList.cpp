//==============================================================================
// 83. Remove Duplicates from Sorted List
// C++
// Tag: Linked List
//==============================================================================
// Summary:
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/#/description

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = new ListNode(0);
        ListNode* current = res;
        res->next = head;
        
        while (current->next) {
            while (current->next && current->next->next && current->next->val == current->next->next->val) {
                current->next = current->next->next;
            }
            current = current->next;
        }
        
        return res->next;
    }
};
