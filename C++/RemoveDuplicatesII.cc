class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 2)
        {
            return n;
        }
        
        int prev = A[0];
        int count = 1;
        int j = 1;
        
        for (int i = 1; i < n; i++)
        {
            if (prev == A[i])
            {
                count++;
                if (count > 2)
                {
                    continue;
                }
            }
            else
            {
                count = 1;
                prev = A[i];
            }
            A[j++] = A[i];
        }
        
        return j;
    }
};