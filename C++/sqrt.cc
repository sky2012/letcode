class Solution {
public:
    int sqrt(int x) {
        long long low = 0;
        long long high = x;
        
        while (low <= high)
        {
            long long mid = (high - low) / 2 + low;
            
            if (mid * mid > x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return int(high);
    }
};

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
