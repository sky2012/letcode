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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode *current = head->next;
        ListNode *prev = head;
     
        while (current != NULL)
        {  
            if (current->val == prev->val)
            {
                prev->next = current->next;
                delete current;
            }
            else
            {
                prev = current;
            }
            
            current = current->next;
        }
        
        return head;       
    }
};