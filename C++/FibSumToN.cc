#include <iostream>

using namespace std;

int fibSumToN(int n)
{
	int prev = 0;
	int current = 1;
	int next = 0;
	
	if (n == 0)
	{
		return prev;
	}
	
	for (int i = 2; i <= n; i++)
	{
		next = prev + current;
		prev = current;
		current = next;
	}
	
	return current;
}