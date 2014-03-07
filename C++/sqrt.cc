class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x <= 0)
        {
            return 0;
        }
        
        long long low = 0;
        long long high = x + 1;
        
        while (low < high - 1)
        {
            long long mid = low + (high - low) / 2;
            
            if (mid * mid <= x)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        
        return low;
    }
};