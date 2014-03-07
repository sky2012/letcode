void setZeroes(vector<vector<int> > &matrix) 
{
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int row = matrix.size();
	int col = matrix[0].size();
	bool *zeroRow = new bool[row];
	bool *zeroCol = new bool[col];
	memset(zeroRow, false, row);
	memset(zeroCol, false, col);
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == 0)
			{
				zeroRow[i] = true;
				zeroCol[j] = true;
			}
		}
	}
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (zeroRow[i] == true || zeroCol[j] == true)
			{
				matrix[i][j] = 0;
			}
		}
	}
}
