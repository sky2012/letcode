void merge(int A[], int m, int B[], int n) 
{
	int len = m + n - 1;
	int i = m - 1;
	int j = n - 1;
	
	while (i >= 0 && j >= 0)
	{
		if (A[i] >= B[j])
		{
			A[len--] = A[i--];
		}
		else
		{
			A[len--] = B[j--];
		}
	}
	
	while (j >= 0)
	{
		A[len--] = B[j--];
	}
}