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
        vector<int> path;
        vector<vector<int> > result;
        pathSumHelper(root, sum, path, result);
        return result;
        
    }
    
    void pathSumHelper(TreeNode *root, int sum, vector<int> sol, vector<vector<int> > &result)
    {
        if (root == NULL)
        {
            return;
        }
        
        sum -= root->val;
        sol.push_back(root->val);
        
        if (sum == 0 && root->left == NULL && root->right == NULL)
        {
            result.push_back(sol);
        }
        
        pathSumHelper(root->left, sum, sol, result);
        pathSumHelper(root->right, sum, sol, result);
    }
};