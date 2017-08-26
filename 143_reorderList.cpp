//==============================================================================
// 143. Reorder List
// C++
// Tag: Linked List
//==============================================================================
// Summary:
// https://leetcode.com/problems/reorder-list/description/

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
    void reorderList(ListNode* head) {
        ListNode *currentNode = head;
        
        if (!currentNode || !currentNode->next) {
            return;
        }
        
        ListNode *midNode = helper1(currentNode);
        midNode->next = helper2(midNode->next);
        
        while (currentNode->next && currentNode->next->next) {
            ListNode *tmp = currentNode->next;
            currentNode->next = midNode->next;
            midNode->next = currentNode->next->next;  
            currentNode->next->next = tmp;        
            currentNode = tmp;                     
        }
    }
        
private: 
    ListNode *helper1(ListNode *nodeIn) {
        ListNode *left = nodeIn;
        ListNode *right = nodeIn->next;
        
        while (right && right->next) {
            left = left->next;
            right = right->next->next;
        }
        
        return left;
    }
    
    ListNode *helper2(ListNode *nodeIn) {
        ListNode *prev = NULL;
        
        while (nodeIn) {
            ListNode *tmp = nodeIn->next;
            nodeIn->next = prev;
            prev = nodeIn;
            nodeIn = tmp;
            
        }
        
        return prev;
    }
};
