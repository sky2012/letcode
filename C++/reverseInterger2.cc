class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x <= 9 && x >= -9)
        {
            return x;
        }
        
        long long value = 0;
        int sign = 1;
        
        if (x <= 0)
        {
            x = -x;
            sign = -1;
        }
        
        while (x > 0)
        {
            value = value * 10 + x % 10;
            x /= 10;
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