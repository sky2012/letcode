double atof(char *s)
{	
	// s == NULL;
	
	int i = 0;
	
	for (; s[i] == ' '; i++)
	{
		;
	}
	
	int sign = ((s[i] == '-') ? -1 : 1);
	
	if (s[i] == '+' || s[i] == '-')
	{
		i++;
	}
	
	float value = 0;
	float power = 0;
	
	for (; s[i] >= '0' && s[i] <= '9'; i++)
	{
		value = value * 10 + s[i] - '0';
	}
	
	if (s[i] == '.')
	{
		i++;
	}
	
	for (; s[i] >= '0' && s[i] <= '9'; i++)
	{
		value = value * 10 + s[i] - '0';
		power *= 10.0;
	} 
	
	return (sign * value / power);
}
	