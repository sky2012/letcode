void serializeTree(TreeNode *root, vector<int> nodeVect)
{
	TreeNode *current = root;
	
	if (!current)
	{
		nodeVect.push_back(-1);
		return;
	}
	
	nodeVect.push_back(current->val);
	serializeTree(current->left, nodeVect);
	serializeTree(current->right, nodeVect);
}

TreeNode* deserializeTree(vector<int> nodeVect)
{
	if (nodeVect.empty())
	{
		return NULL;
	}
	
	if (nodeVect.front() == -1)
	{
		nodeVect.pop_front();
		return NULL;
	}
	
	TreeNode *root = new TreeNode(nodeVect.front());
	TreeNode.pop_front();
	root->left = deserializeTree(nodeVect);
	root->right = deserailzeTree(nodeVect);
	
	return root;
}
		
	
	