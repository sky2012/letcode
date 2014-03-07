class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || k <= 1)
        {
            return head;
        }
        
        ListNode *current = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;    
        int count = 0;
        
        while (current != NULL && count < k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        
        if (next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }
        
        return prev;     
    }
};