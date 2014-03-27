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
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        for (int i = 0; i < n; i++)
        {
            if (!fast)
            {
                return NULL;
            }
            
            fast = fast->next;
        }
        
        if (!fast)
        {
            slow = slow->next;
            delete head;
            return slow;
        }
        
        ListNode *prev = slow;
        
        while (fast)
        {
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
        
        prev->next = slow->next;
        delete slow;
        return head;
    }
};