#include <iostream>

using namespace std;

int evaluatePolishNotation(string exp)
{
	int len = exp.size();
	
	if (len == 0)
	{
		return 0;
	}
	
	int operand1 = 0;
	int operand2 = 0;
	stack<int> numStack;
	string num;
	
	for (int i = 0; i < len; i++)
	{
		if (isdigit(exp[i])
		{
			num.push_back(