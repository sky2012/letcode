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
            sign = -1;
            n = -n;
        }
        
        for (int i = n; i >= 1; i /= 2)
        {
            if (i % 2 == 1)
            {
                result *= x;
            }
            
            x *= x;
        }
        
        if (sign > 0)
        {
            return result;
        }
        else
        {
            return 1 / result;
        }
    }
};