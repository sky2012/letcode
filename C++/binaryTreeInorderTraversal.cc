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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> nodeStack;
        
        if (!root)
        {
            return result;
        }
        
        TreeNode *ptr = root;
        
        while (ptr || !nodeStack.empty())
        {
            if (ptr)
            {
                nodeStack.push(ptr);
                ptr = ptr->left;
            }
            else
            {
                ptr = nodeStack.top();
                result.push_back(ptr->val);
                nodeStack.pop();
                ptr = ptr->right;
            }
        }
        
        return result;
    }
};
