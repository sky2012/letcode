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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        priority_queue<ListNode *, vector<ListNode *>, greaterNode> nodeQueue;
        
        vector<ListNode *>::iterator it;
        
        for (it = lists.begin(); it != lists.end(); it++)
        {
            if (*it != NULL)
            {
                nodeQueue.push(*it);
            }
        }
        
        if (nodeQueue.empty())
        {
            return false;
        }
        
        ListNode *head = NULL;
        ListNode *tail = NULL;
        
        while (!nodeQueue.empty())
        {
            ListNode *node = nodeQueue.top();
            
            if (!head)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = tail->next;
            }
            
            nodeQueue.pop();
            
            if (node->next)
            {
                nodeQueue.push(node->next);
            }
        }
    
        return head;
        
    }
    
    struct greaterNode
    {
        bool operator() (const ListNode *a, const ListNode *b)
        {
            return a->val > b->val;
        }
    };
};