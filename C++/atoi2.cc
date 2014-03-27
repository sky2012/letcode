class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (str == NULL)
        {
            return 0;
        }
        
        int sign = 1;
        long long value = 0;
        
        int index = 0;
        
        for (; str[index] == ' '; index++)
        {
        }
        
        sign = (str[index] == '-' ? -1 : 1);
        
        if (str[index] == '+' || str[index] == '-')
        {
            index++;
        }
        
        for (; str[index] <= '9' && str[index] >= '0'; index++)
        {
            value = value * 10 + str[index] - '0';
        }
        
        if (sign == 1)
        {
            return (value > INT_MAX ? INT_MAX : value);
        }
        else
        {
            return (value * sign < INT_MIN ? INT_MIN : value * sign);
        }
    }
};