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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head)
        {
            return head;
        }
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = head;
        
        while (second && second->next)
        {
            ListNode *next = second->next->next;
            second->next->next = first->next;
            first->next = second->next;
            second->next = next;
            first = second;
            second = first->next;
        }
        
        return dummy->next;
    }
};