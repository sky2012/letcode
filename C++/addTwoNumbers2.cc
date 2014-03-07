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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        int carry = 0;
        ListNode *result = NULL;
        ListNode *ptr = NULL;
        
        while (ptr1 || ptr2)
        {
            int value1 = 0;
            int value2 = 0;
            
            if (ptr1)
            {
                value1 = ptr1->val;
                ptr1 = ptr1->next;
            }
            else
            {
                value1 = 0;
            }
            
            if (ptr2)
            {
                value2 = ptr2->val;
                ptr2 = ptr2->next;
            }
            else
            {
                value2 = 0;
            }
            
            
            int sum = value1 + value2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            
            if (result == NULL)
            {
                result = new ListNode(digit);
                ptr = result;
            }
            else
            {
                ptr->next = new ListNode(digit);
                ptr = ptr->next;
            }
        }
        
        if (carry > 0)
        {
            ptr->next = new ListNode(carry);
        }
        
        return result;
    }
};