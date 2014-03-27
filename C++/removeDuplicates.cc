class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1)
        {
            return n;
        }
        
        int newLen = 1;
        
        for (int i = 1; i < n; i++)
        {
            if (A[i] != A[i-1])
            {
                A[newLen++] = A[i];
            }
        }
        
        return newLen;
    }
};