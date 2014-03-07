string multiply(string num1, string num2) 
{
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int len1 = num1.size();
	int len2 = num2.size();
	
	if (len1 == 0 || len2 == 0)
	{
		return "";
	}
	
	int len3 = len1 + len2;
	
	int num[len3];
	memset(num, 0, sizeof(int) * len3);
	int carry = 0;
	int temp = 0;
	int i, j;
	
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		
		for (j = len2 - 1; j >= 0; j--)
		{
			temp = carry + num[i + j + 1] + (num1[i] - '0') * (num2[j] - '0');
			num[i + j + 1] = temp % 10;
			carry = temp / 10;
		}
		
		num[i + j + 1] = carry;
	}
	
	string str3 = "";
	i = 0;
	
	while (i < len3 - 1 && num[i] == 0)
	{
		i++;
	}
	
	while (i < len3)
	{
		str3.push_back(num[i++] + '0');
	}
	
	return str3;	
}