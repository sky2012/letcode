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
        vector<int> levelNode;
        
        if (!root)
        {
            return result;
        }
        
        int treeDepth = getTreeDepth(root);
        
        for (int i = treeDepth; i >= 1; i--)
        {
            levelNode.clear();
            printLevel(root, i, levelNode);
            result.push_back(levelNode);
        }
        
        return result;
    }
    
    void printLevel(TreeNode *root, int level, vector<int> &node)
    {
        if (!root)
        {
            return;
        }
        
        if (level == 1)
        {
            node.push_back(root->val);
        }
        
        printLevel(root->left, level - 1, node);
        printLevel(root->right, level - 1, node);
    }
    
    int getTreeDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        
        int leftDepth = getTreeDepth(root->left);
        int rightDepth = getTreeDepth(root->right);
        
        return max(leftDepth, rightDepth) + 1;
    }
};