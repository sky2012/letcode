int lengthOfLastWord(const char *s) 
{
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int len = strlen(s);
	
	int i = len - 1;
	while (i >= 0 && s[i] == ' ')
	{
		i--;
	}
	
	if (i < 0)
	{
		return 0;
	}
	
	int num = 0;
	
	while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
	{
		i--;
		num++;
	}
	return num;
}