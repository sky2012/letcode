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
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int currentSum;
        int maxSum = INT_MIN;
        maxPathSumHelper(root, currentSum, maxSum);
        return maxSum;
    }
    
    void maxPathSumHelper(TreeNode *root, int &currentSum, int &maxSum)
    {
        if (root == NULL)
        {
            currentSum = 0;
            return;
        }
        
        int leftSum = 0;
        int rightSum = 0;
        maxPathSumHelper(root->left, leftSum, maxSum);
        maxPathSumHelper(root->right, rightSum, maxSum);
        
        currentSum = max(root->val, max(root->val + leftSum, root->val + rightSum));
        maxSum = max(maxSum, max(currentSum, root->val + leftSum + rightSum));
    }
};