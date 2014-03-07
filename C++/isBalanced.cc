bool isBalanced(TreeNode *root) 
{
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (root == NULL)
	{
		return true;
	}
	
	int depthLeft = depth(root->left);
	int depthRight = depth(root->right);
	
	if (abs(depthLeft - depthRight) > 1)
	{
		return false;
	}
	
	return isBalanced(root->left) && isBalanced(root->right);	
}

int depth(TreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	
	int leftDepth = depth(root->left);
	int rightDepth = depth(root->right);
	
	return max(leftDepth + 1, rightDepth + 1);
}