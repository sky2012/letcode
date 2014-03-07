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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return convertToBSTHelper(num, 0, num.size() - 1);
    }
    
    TreeNode *convertToBSTHelper(vector<int> &num, int low, int high)
    {
        
        if (low > high)
        {
            return NULL;
        }
        else
        {
            int mid = (high - low) / 2 + low;
        
            TreeNode *root = new TreeNode(num[mid]);
            root->left = convertToBSTHelper(num, low, mid - 1);
            root->right = convertToBSTHelper(num, mid + 1, high);
        
            return root;
        }
    }
};