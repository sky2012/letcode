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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 0)
        {
            return head;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = slow;
        
        for (int i = 0; i < n; i++)
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
        
        while (fast != NULL)
        {
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
        
        prev->next = slow->next;
        return head;
        
    }
};