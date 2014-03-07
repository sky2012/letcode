class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = 0;
        int high = n - 1;
        int index = 0;
        
        while (index <= high)
        {
            if (A[index] == 0)
            {
                swapElement(A, index, low);
                index++;
                low++;
            }
            else if (A[index] == 1)
            {
                index++;
            }
            else
            {
                swapElement(A, index, high);
                high--;
            }
        }
    }
    
    void swapElement(int arr[], int i, int j)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};