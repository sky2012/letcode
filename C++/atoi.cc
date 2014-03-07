int atoi(const char *str) 
{
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	
	int i = 0;
	int sign = 1;
	int value = 0;
	int bound = INT_MAX / 10;
   
	for (; str[i] == ' '; i++)
	{
		
	}
	
	sign = ((str[i] == '-') ? -1 : 1);
	
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}
	
	while (isdigit(str[i]) && bound != 0)
	{
		value = value * 10 + str[i] - '0';
		bound /= 10;
		i++;
	}
	
	if (!isdigit(str[i]))
	{
		return (sign * value);
	}
	
	if (value > INT_MAX / 10)
	{ 
		return ((sign == 1) ? INT_MAX : INT_MIN);
	}
	else if (value == INT_MAX / 10)
	{
		if (str[i] - '0' > abs(((sign == 1) ? INT_MAX : INT_MIN) % 10))
		{
			return ((sign == 1) ? INT_MAX : INT_MIN);
		}
		else
		{
			return (sign * (value * 10 + (str[i] - '0')));
		}
	}
	else
	{
		return (sign * (value * 10 + (str[i] - '0')));
	}	
}