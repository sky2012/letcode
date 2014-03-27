/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
        {
            return;
        }
        
        TreeLinkNode *current = root;
        TreeLinkNode *prev = NULL;
        TreeLinkNode *next = NULL;
        
        while (current)
        {
            if (current->left)
            {
                if (prev)
                {
                    prev->next = current->left;
                }
                
                prev = current->left;
                
                if (!next)
                {
                    next = current->left;
                }
            }
            
            if (current->right)
            {
                if (prev)
                {
                    prev->next = current->right;
                }
                
                prev = current->right;
                
                if (!next)
                {
                    next = current->right;
                }
            }
            
            current = current->next;
        }
        
        connect(next);
    }
};