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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        vector<int> pathVect;
        pathSumHelper(root, sum, pathVect, result);
        
        return result;
    }
    
    void pathSumHelper(TreeNode *root, int sum, vector<int> nodeVect, vector<vector<int> > &result)
    {
        if (root == NULL)
        {
            return;
        }
        
        sum -= root->val;
        nodeVect.push_back(root->val);
        
        if (sum == 0 && root->left == NULL && root->right == NULL)
        {
            result.push_back(nodeVect);
            return;
        }
        else
        {
            pathSumHelper(root->left, sum, nodeVect, result);
            pathSumHelper(root->right, sum, nodeVect, result);
        }
    }
};