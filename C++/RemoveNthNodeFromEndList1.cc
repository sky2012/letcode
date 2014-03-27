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
        if (!head || n <= 0)
        {
            return head;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        for (int i = 0; i < n; i++)
        {
            if (!fast)
            {
                return head;
            }
            fast = fast->next;
        }
        
        if (!fast)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head; 
        }
        
        ListNode *prev = NULL;
        while (fast)
        {
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *temp = slow;
        prev->next = slow->next;
        delete temp;
        return head; 
    }
};