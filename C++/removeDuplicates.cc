int removeDuplicates(int A[], int n) 
{
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (n == 0)
	{
		return 0;
	}
	
	int i = 1;
	int j = 1;
	
	for (; i < n; i++)
	{
		if (A[i] != A[i - 1])
		{
			A[j++] = A[i];
		}
	}
	
	return j;
}