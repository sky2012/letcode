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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = 0;
        
        if (!root)
        {
            return 0;
        }
        
        sumNumbersHelper(root, 0, result);
        return result;
    }
    
    void sumNumbersHelper(TreeNode *root, int pathSum, int &result)
    {
        pathSum += root->val;
        
        if (!root->left && !root->right)
        {
            result += pathSum;
            return;
        }
        
        pathSum *= 10;
        
        if (root->left)
        {
            sumNumbersHelper(root->left, pathSum, result);
        }
        
        if (root->right)
        {
            sumNumbersHelper(root->right, pathSum, result);
        }
    }
};