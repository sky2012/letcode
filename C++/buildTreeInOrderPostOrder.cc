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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTreeHelper(inorder.begin(), postorder.begin(), inorder.size());
        
    }
    
    TreeNode *buildTreeHelper(vector<int>::iterator iterIn, vector<int>::iterator iterPost, int size)
    {
        if (size == 0)
        {
            return NULL;
        }
        
        
        vector<int>::iterator it = find(iterIn, iterIn + size, *(iterPost + size - 1));
        int index = it - iterIn;
        
        TreeNode *root = new TreeNode(*it);
        
        root->left = buildTreeHelper(iterIn, iterPost, index);
        root->right = buildTreeHelper(iterIn + index + 1, iterPost + index, size - index - 1);
        
		return root;
    }
};