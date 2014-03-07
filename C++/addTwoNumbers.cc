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
       if (!l1 && !l2)
       {
           return NULL;
       }
       
       ListNode *newList = NULL;
       ListNode *current = NULL;
       ListNode *newNode = NULL;
       int carry = 0;
       int sum = 0;
       int value = 0;
        
        while (l1 || l2)
        {
            value = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = (value >= 10) ? 1 : 0;
            sum = value % 10;
            
            ListNode *newNode = new ListNode(sum);
            
            if (!newList)
            {
                newList = newNode;
            }
            else
            {
                current->next = newNode;
            }
            
            current = newNode;
            
            if (l1)
            {
                l1 = l1->next;
            }
            
            if (l2)
            {
                l2 = l2->next;
            }
        }
        
        
        if (carry == 1)
        {
           newNode = new ListNode(carry);
           current->next = newNode;
        }
        
        return newList;
            
    }
};