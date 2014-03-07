int climbStairs(int n) 
{
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (n <= 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		int prev = 1;
		int prePrev = 0;
		int result = 0;
		
		for (int i = 1; i <= n; i++)
		{
			result = prev + prePrev;
			prePrev = prev;
			prev = result;
		}
		
		return result;
	}
	
}