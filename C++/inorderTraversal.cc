public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        stack<TreeNode *> nodeStack;
        
        while (root != NULL || !nodeStack.empty())
        {
            if (root != NULL)
            {
                nodeStack.push(root);
                root = root->left;
            }
            else
            {
                TreeNode *ptr = nodeStack.top();
                result.push_back(ptr->val);
                nodeStack.pop();
                root = root->right;
            }
        }
        
        return result;      
    }
};