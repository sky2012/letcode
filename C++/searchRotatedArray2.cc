class Solution {
public:
    bool search(int A[], int n, int target) {
        int low = 0;
        int high = n - 1;
        
        while (low <= high)
        {
            int mid = (high - low) / 2 + low;
            
            if (A[mid] == target)
            {
                return true;
            }
            
            if (A[low] < A[mid])
            {
                if (A[low] <= target && target <= A[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else if (A[low] > A[mid])
            {
                if (A[mid] <= target && target <= A[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            else
            {
                low++;
            }
        }
        
        return false;
    }
};


class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int low = 0;
        int high = n - 1;
        return searchHelper(A, low, high, target);      
    }
    
    bool searchHelper(int A[], int low, int high, int target)
    {
        if (low > high)
        {
            return false;
        }
           
        int mid = (high - low) / 2 + low;
        
        if (A[mid] == target)
        {
            return true;
        }
        
        if (A[low] < A[mid])
        {
            if (A[low] <= target && target <= A[mid])
            {
                return searchHelper(A, low, mid - 1, target);
            }
            else
            {
                return searchHelper(A, mid + 1, high, target);
            }
        }
        else if (A[low] > A[mid])
        {
            if (A[mid] <= target && target <= A[high])
            {
                return searchHelper(A, mid + 1, high, target);
            }
            else
            {
                return searchHelper(A, low, mid - 1, target);
            }
        }
        else
        {
            if (A[mid] != A[high])
            {
                return searchHelper(A, mid + 1, high, target);
            }
            else
            {
                bool lresult = searchHelper(A, low, mid - 1, target);
                bool rresult = searchHelper(A, mid + 1, high, target);
                
                return (lresult ? lresult : rresult);
            }
        }
    }
};
