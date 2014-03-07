#include <iostream>
#include <string.h>

using namespace std;

void swap(char *a, char *b)
{
     char temp;
     temp = *a;
     *a = *b;
     *b = temp;
}

bool isSwap(char *str, int begin, int end)
{
     for (int i = begin; i <= end; i++)
     {
         if (str[i] == str[end])
         {
               return false;
         }
     }
     
     return true;
}

void permutation(char *str, int pos, int end)
{
	if (pos == end)
	{
		cout << str << endl;
	}
	else
	{
        for (int i = pos; i <= end; i++)
		{
			if (isSwap(str, i, pos))
			{
               swap(str+i, str+pos);
			   permutation(str, pos+1, end);
			   swap(str+i, str+pos);
           }
		}
	}
}

int main()
{   
      char mystr[20];
      cin.getline(mystr, 20);
      int len = strlen(mystr);
      permutation(mystr, 0, len - 1);
      
      system("pause");     
      return 0;
}
