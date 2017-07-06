//==============================================================================
// 25. Reverse Nodes in k-Group
// C++
// Tag: Linked List
//==============================================================================
// Summary:
// https://leetcode.com/problems/reverse-nodes-in-k-group/#/description

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        
        for (int i = 0; i < k; i++) {
            if (node == NULL) {
                return head; 
            }
            node = node -> next;
        }

        ListNode* res = helper(head, node);
        head -> next = reverseKGroup(node, k);
        
        return res;
    }
    
private: 
    ListNode* helper(ListNode* head, ListNode* tail) {
        ListNode* prev = tail;
        ListNode* current = head;
        
        while (current != tail) {
            ListNode* tmp = current -> next;
            current -> next = prev;
            prev = current;
            current = tmp;
        }
        
        return prev;
    }
};
