string excelCol(int col)
{
	string result(1, col % 26 + 'A');
	col = col / 26;
	
	while (col > 0)
	{
		result.push_back((col - 1) % 26 + 'A');
		col = (col - 1) % 26;
	}
	
	return result;
}