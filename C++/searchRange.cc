class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result(2, -1);
        int lowBound = getLowerBound(A, n, target);
        int highBound = getHighBound(A, n, target);
        
        if (lowBound <= highBound)
        {
            result[0] = lowBound;
            result[1] = highBound;
        }
        
        return result;
    }
    
    int getLowerBound(int A[], int n, int target)
    {
        int low = 0;
        int high = n - 1;
        
        while (low <= high)
        {
            int mid = (high - low) / 2 + low;
            
            if (target <= A[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return low;
    }
    
    int getHighBound(int A[], int n, int target)
    {
        int low = 0;
        int high = n - 1;
        
        while (low <= high)
        {
            int mid = (high - low) / 2 + low;
            
            if (target < A[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return high;
    }
};
