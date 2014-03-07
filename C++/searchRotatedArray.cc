class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = 0;
        int high = n - 1;
        
        while (low <= high)
        {
            int mid = (high - low) / 2 + low;
        
            if (A[mid] == target)
            {
                return mid;
            }
        
            if (A[low] <= A[mid])
            {
                if (A[low] <= target && target < A[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (A[mid] < target && target <= A[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        
        return -1;
    }
};