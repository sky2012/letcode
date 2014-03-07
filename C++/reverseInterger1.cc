int reverse(int x) 
{
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int sign = 1;
	
	if ((sign = x) < 0)
	{
		x = -x;
	}
	
	int result = 0;
	
	while (x)
	{
		result = result * 10 + x % 10;
		x = x / 10;
	}
	
	if (sign < 0)
	{
		result = -result;
	}
	
	return result;
}