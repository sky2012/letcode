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
        if (!head || !head->next)
        {
            return NULL;
        }
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast == slow)
            {
                break;
            }
        }
        
        if (!fast || !fast->next)
        {
            return NULL;
        }
        
        slow = head;
        
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        return fast;
    }
};
