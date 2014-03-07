class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0)
        {
            return 1;
        }
        
        int sign = 1;
        double result = 1.0;
        
        if (n < 0)
        {
            n = -n;
            sign = -1;
        }
        
        while (n > 0)
        {
            if (n & 1)
            {
                result *= x;
            }
            n = n >> 1;
            x *= x;   
        }
        
        if (sign == 1)
        {
            return result;
        }
        else
        {
            return (1.0 / result);
        }
    }
};