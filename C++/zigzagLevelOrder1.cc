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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        
        if (!root)
        {
            return result;
        }
        
        int treeDepth = getTreeDepth(root);
        
        for (int i = 1; i <= treeDepth; i++)
        {
            vector<int> nodeVect;
            printGivenOrder(root, i, nodeVect);
            if (i % 2 == 0)
            {
                reverse(nodeVect.begin(), nodeVect.end());
            }
            result.push_back(nodeVect);
        }
        
        return result;
    }
    
    void printGivenOrder(TreeNode *root, int level, vector<int> &vectNode)
    {
        if (!root)
        {
            return;
        }
        
        if (level == 1)
        {
            vectNode.push_back(root->val);
        }
        else
        {
            printGivenOrder(root->left, level - 1, vectNode);
            printGivenOrder(root->right, level - 1, vectNode);
        }
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