class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (A == NULL || n == 0)
        {
            return 0;
        }
        
        int sum = 0;
        int maxSum = 0;
        
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            
            if (sum > maxSum)
            {
                maxSum = sum;
            }
            else if (sum < 0)
            {
                sum = 0;
            }
        }
        
        if (maxSum == 0)
        {
            maxSum = A[0];
            
            for (int i = 1; i < n; i++)
            {
                if (maxSum < A[i])
                {
                    maxSum = A[i];
                }
            }
        }
       
        return maxSum;

    }
};