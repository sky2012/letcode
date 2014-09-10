class Solution {
public:
    int reverse(int x) {
        if (x >= -9 && x <= 9)
        {
            return x;
        }
        
        long long value = 0;
        int sign = 1;
        
        if (x < 0)
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
            return (value >= INT_MAX ? INT_MAX : value);
        }
        else
        {
            return (value * (-1) <= INT_MIN ? INT_MIN : (-1) * value);
        }
    }
};
