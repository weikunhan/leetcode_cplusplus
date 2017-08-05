//==============================================================================
// 203. Remove Linked List Elements
// C++
// Tag: Math(Hash Table)
//==============================================================================
// Summary:
// https://leetcode.com/problems/remove-linked-list-elements/description/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *res = new ListNode(0);
        ListNode *current = res;
        res->next = head;
        
        while (current->next) {
            if (current->next->val == val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        
        return res->next;
    }
};
