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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        return buildTreeHelper(preorder.begin(), inorder.begin(), preorder.size());
    }
    
    TreeNode *buildTreeHelper(vector<int>::iterator iterPre, vector<int>::iterator iterIn, int size)
    {
        if (size == 0)
        {
            return NULL;
        }
        
        vector<int>::iterator it = find(iterIn, iterIn + size, *iterPre);
        int index = it - iterIn;
        
        TreeNode *root = new TreeNode(*iterPre);
        root->left = buildTreeHelper(iterPre + 1, iterIn, index);
        root->right = buildTreeHelper(iterPre + 1 + index, iterIn + 1 + index, size - index - 1);
        
        return root;
    }
};