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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        int depth = getDepth(root);
        
        for (int i = depth; i >= 1; i--)
        {
            vector<int> levelNode;
            printLevel(root, i, levelNode);
            result.push_back(levelNode);
        }
        
        return result;
    }
    
    void printLevel(TreeNode *root, int level, vector<int>& nodeVect)
    {
        if (!root)
        {
            return;
        }
        
        if (level == 1)
        {
            nodeVect.push_back(root->val);
        }
        else
        {
            printLevel(root->left, level - 1, nodeVect);
            printLevel(root->right, level - 1, nodeVect);
        }
    }
    
    int getDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        
        return ((leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1);
    }
};