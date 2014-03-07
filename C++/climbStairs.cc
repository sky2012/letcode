int climbStairs(int n)
{
	if (n < 0)
    {
		exit(1);
	}
	if (n == 0 || n == 1)
	{
		return 1;
	}
	int prev = 1;
	int prevpre = 1;
	int sum = 1;
	for (int i = 2; i <= n; i++)
	{
		sum = prev + prevpre;
		prevpre = prev;
		prev = sum;
	}
	return sum;
}