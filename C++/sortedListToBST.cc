/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ptr = head;
        int length = 0;
        
        while (ptr != NULL)
        {
            ptr = ptr->next;
            length++;
        }
        
        return listToBSTHelper(head, 0, length - 1);
    }
    
    TreeNode *listToBSTHelper(ListNode *&head, int low, int high)
    {
        if (low > high)
        {
            return NULL;
        }
        
        int mid = (high - low) / 2 + low;
        
        TreeNode *lchild = listToBSTHelper(head, low, mid - 1);
        TreeNode *root = new TreeNode(head->val);
        root->left = lchild;
        head = head->next;
        root->right = listToBSTHelper(head, mid + 1, high);
        
        return root;         
    }
};