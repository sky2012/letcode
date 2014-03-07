string countAndSay(int n)
{
	if (n < 0)
	{
		exit(1);
	}
	
	int digit = 0;
	int prev = -1;
	int num = 1;
	string str;
	string::iterator it;
	while (n > 0)
	{
		digit = n % 10;
		if (digit == prev)
		{
			num++;
		}
		else
		{
			it = str.begin();
			str.insert(it, ('0' + digit));
			it = str.begin();
			str.insert(it, ('0' + num));
			prev = digit;
			num = 1;
		}
		digit = digit / 10;
	}
	return str;
}
		