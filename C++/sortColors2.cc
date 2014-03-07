class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int red = 0;
        int green = 0;
        int blue = 0;
        
        for (int i = 0; i < n; i++)
        {
            switch (A[i])
            {
                case 0:
                    red++;
                    break;
                case 1:
                    green++;
                    break;
                case 2:
                    blue++;
                    break;
            } 
        }
        
        for (int i = 0; i < n; i++)
        {
            if (i < red)
            {
                A[i] = 0;
            }
            else if (i >= red && i < green + red)
            {
                A[i] = 1;
            }
            else
            {
                A[i] = 2;
            }
        }
    }
};