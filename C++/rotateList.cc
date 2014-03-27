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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head || !head->next || k <= 0)
        {
            return head;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        for (int i = 1; i <= k; i++)
        {
            if (fast == NULL)
            {
                return head;
            }
            
            fast = fast->next;
        }
        
        if (fast == NULL)
        {
            return head;
        }
        
        while (!fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *newHead = slow->next;
        slow->next = NULL;
        fast->next = head;
        
        return newHead;
    }
};