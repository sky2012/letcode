class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (A == NULL || n == 0)
        {
            return 0;
        }
        
        int index = 0;
        int newIndex = 0;
        
        for (int index = 0; index < n; index++)
        {
            if (A[index] == elem)
            {
                continue;
            }
            
            A[newIndex++] = A[index];
        }
        
        return newIndex;
    }   
};