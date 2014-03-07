string intToRoman(int num) 
{
	// Start typing your C/C++ solution below
	// DO NOT write int main() function   
	string digit[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	string ten[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	string hundred[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	string thousand[10] = {"", "M", "MM", "MMM"};
	
	if (num > 3999)
	{
		num = 3999;
	}
	
	if (num < 0)
	{
		num = 0;
	}
	
	string result;
	result.append(thousand[num/1000]);
	result.append(hundred[(num/100) % 10]);
	result.append(ten[(num/10) % 10]);
	result.append(digit[num % 10]);
	return result;
}
	
	
	input	output	expected	
1	"I"	"I"	
   
2	"II"	"II"	
   
3	"III"	"III"	
   
4	"IV"	"IV"	
   
5	"V"	"V"	
   
6	"VI"	"VI"	
   
7	"VII"	"VII"	
   
8	"VIII"	"VIII"	
   
9	"IX"	"IX"	
   
10	"X"	"X"	
   
11	"XI"	"XI"	
   
13	"XIII"	"XIII"	
   
14	"XIV"	"XIV"	
   
15	"XV"	"XV"	
   
16	"XVI"	"XVI"	
   
18	"XVIII"	"XVIII"	
   
19	"XIX"	"XIX"	
   
20	"XX"	"XX"	
   
25	"XXV"	"XXV"	
   
90	"XC"	"XC"	
   
99	"XCIX"	"XCIX"	
   
100	"C"	"C"	
   
900	"CM"	"CM"	
   
990	"CMXC"	"CMXC"	
   
1000	"M"	"M"	
   
1001	"MI"	"MI"	
   
1500	"MD"	"MD"	
   
1999	"MCMXCIX"	"MCMXCIX"	
   
2012	"MMXII"	"MMXII"	
   
3999	"MMMCMXCIX"	"MMMCMXCIX"	
   