 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        
        ListNode *temp = head;
        
        while (temp && temp->next)
        {
            swap(&(temp->val), &(temp->next->val));
            temp = temp->next->next;
        }
        
        return head;
    }
    
    void swap(int *a, int *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
};