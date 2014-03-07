bool searchMatrix(vector<vector<int> > &matrix, int target) 
{
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int col = matrix[0].size();
	int row = matrix.size();
	
	int i = 0;
	int j = col - 1;
	
	while (i < row && j >= 0)
	{ 
		if (matrix[i][j] > target)
		{
			j--;
		}
		else if (matrix[i][j] < target)
		{
			i++;
		}
		else
		{
			return true;
		}
	}
	
	return false;
}