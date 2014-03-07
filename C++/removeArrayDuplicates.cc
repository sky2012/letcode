class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 2)
        {
            return n;
        }
        
        int count = 0;
        int index = 1;
        
        for (int i = 1; i < n; i++)
        {
            if (A[i] == A[i - 1])
            {
                count++;
                if (count >= 2)
                {
                    continue;
                }
            }
            else
            {
                count = 0;
            }
            
            A[index++] = A[i];
        }
        
        return index;
    }
};