string expandString(string str, int low, int high)
{
	int len = str.length();
	
	int left = low;
	int right = high;
	
	while (left >= 0 && right < len && str[left] == str[right])
	{
		left--;
		right++;
	}
	
	return str.substr(left + 1, right - 1 - left);
}

string longestPalindrome(string str)
{
	int len = str.length();
	
	if (len == 0 || len == 1)
	{
		return str;
	}
	
	string longest = str.substr(0, 1);
	
	for (int i = 0; i < len - 1; i++)
	{
		string str1 = expandString(str, i, i);
		if (str1.length() > longest.length())
		{
			longest = str1;
		}
		
		string str2 = expandString(str, i, i + 1);
		if (str2.length() > longest.length())
		{
			longest = str2;
		}
	}
	
	
	return longest;
}
	