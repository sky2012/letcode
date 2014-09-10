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
    ListNode *partition(ListNode *head, int x) {
        
        if (!head || !head->next)
        {
            return head;
        }
        
        ListNode *firstHead = NULL;
        ListNode *firstTail = NULL;
        ListNode *secondHead = NULL;
        ListNode *secondTail = NULL;
        ListNode *ptr = head;
        
        while (ptr)
        {
            ListNode *nextPtr = ptr->next;
            ptr->next = NULL;
            
            if (ptr->val < x)
            {
                if (!firstHead)
                {
                    firstHead = ptr;
                    firstTail = ptr;
                }
                else
                {
                    firstTail->next = ptr;
                    firstTail = firstTail->next;
                }
            }
            else
            {
                if (!secondHead)
                {
                    secondHead = ptr;
                    secondTail = ptr;
                }
                else
                {
                    secondTail->next = ptr;
                    secondTail = secondTail->next;
                }
            }
            
            ptr = nextPtr;
        }
        
        if (!firstHead)
        {
            return secondHead;
        }
        
        firstTail->next = secondHead;
        return firstHead;
    }
};
