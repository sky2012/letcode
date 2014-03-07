public class Solution {
    public void sortColors(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        if (A.length < 2)
        {
            return;
        }
        
        int begin = 0;
        int end = A.length - 1;
        int current = 0;
        
        while (current <= end)
        {
            if (A[current] == 0)
            {
                swapElement(A, begin, current);
                begin++;
                current++;
            }
            else if (A[current] == 1)
            {
                current++;
            }
            else
            {
                swapElement(A, current, end);
                end--;
            }
        }
    }
    
    void swapElement(int[] arr, int i, int j)
    {
        int temp;
        
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}