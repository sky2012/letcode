vector<int> spiralOrder(vector<vector<int> > &matrix) 
{
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> result;
    int ROW = matrix.size();
	int COL = matrix[0].size();
	if (ROW == 0 || COL == 0)
	{
		return result;
	}
	
	if (ROW == 1 && COL == 1)
	{
		result.push_back(matrix[0][0]);
		return result;
	}
	
    int rowStart = 0;
    int colStart = 0;
	int rowEnd = ROW - 1;
	int colEnd = COL - 1;
    
    while (rowStart <= rowEnd && colStart <= colEnd)
    {
        for (int i = colStart; i <= colEnd; i++)
        {
            result.push_back(matrix[rowStart][i]);
        }
        
        rowStart++;
        
        for (int i = rowStart; i <= rowEnd; i++)
        {
            result.push_back(matrix[i][colEnd]);
        }
        
        colEnd--;
        
        if (rowStart <= rowEnd)
        {
            for (int i = colEnd; i >= colStart; i--)
            {
                result.push_back(matrix[rowEnd][i]);
            }
            
            rowEnd--;
        }
        
        if (colStart <= colEnd)
        {
            for (int i = rowEnd; i >= rowStart; i--)
            {
                result.push_back(matrix[i][colStart]);
            }
            
            colStart++;
        }
    }
    
    return result;
}