class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (n == 0)
        {
            return 1;
        }

        double result = 1.0;
        int sign = 1;
        double temp = x;
        
        if (n < 0)
        {
            n = -n;
            sign = -1;
        }
        
        for (int i = n; i > 0; i = i / 2)
        {
            if (i % 2 == 1)
            {
                result = result * temp;
            }
            
            temp = temp * temp;
        }
        
        if (sign == 1)
        {
            return result;
        }
        else
        {
            return 1.0/result;
        }
    }
};