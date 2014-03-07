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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        stack<TreeNode *> nodeStack;
        
        while (!nodeStack.empty() || root != NULL)
        {
            if (root != NULL)
            {
                nodeStack.push(root);
                root = root->left;
            }
            else
            {
                root = nodeStack.top();
                result.push_back(root->val);
                nodeStack.pop();
                root = root->right;
            }
        }
        
        return result;
    }
};