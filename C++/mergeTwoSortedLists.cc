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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     if (l1 == NULL)
     {
         return l2;
     }
     
     if (l2 == NULL)
     {
         return l1;
     }
        
     ListNode *pa = l1;
     ListNode *pb = l2;
     ListNode *head = NULL;   
     
     if (pa->val <= pb->val)
     {
          head = pa;
          pa = pa->next;
     }
     else
     {
          head = pb;   
          pb = pb->next;
     } 
     
     ListNode *pc = head;   
     
     while (pa && pb)
     {
           if (pa->val <= pb->val)
           {
               pc->next = pa;
               pc = pa;
               pa = pa->next;
           }
           else
           {
               pc->next = pb;
               pc = pb;
               pb = pb->next;
           }
     }
     
     pc->next = pa ? pa : pb;
     return head;
    }
};