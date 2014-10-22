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
    bool isSymmetric(TreeNode *root) {
        if (!root)
        {
            return true;
        }
        
        return isSymmetricHelper(root->left, root->right);
    }
    
    bool isSymmetricHelper(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
        {
            return true;
        }
        else if (a && !b || !a && b || a->val != b->val)
        {
            return false;
        }
        else
        {
            return isSymmetricHelper(a->left, b->right) && isSymmetricHelper(a->right, b->left);
        }
    }
};
