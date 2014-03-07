bool isPalindrome(int x) 
{
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	
	if (x < 0)
	{
		return false;
	}
	
	int temp = x;
	
	int result = 0;
	
	while (x)
	{
		result = result * 10 + x % 10;
		x = x / 10;
	}
	
	return (result == temp);
}

input	output	expected	
-2147483648	false	false	
   
-2147447412	false	false	
   
-101	false	false	
   
-10	false	false	
   
-1	false	false	
   
0	true	true	
   
1	true	true	
   
3	true	true	
   
5	true	true	
   
10	false	false	
   
11	true	true	
   
44	true	true	
   
121	true	true	
   
123	false	false	
   
213	false	false	
   
313	true	true	
   
1001	true	true	
   
1881	true	true	
   
101	true	true	
   
500	false	false	
   
9999	true	true	
   
88888	true	true	
   
2222222	true	true	
   
789656987	true	true	
   
2147447412	true	true	
   
2147483647	false	false	
   