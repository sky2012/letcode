class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int len = m + n;
        
        if (len % 2)
        {
            return get_kth_element(A, m, B, n, len/2 + 1);
        }
        else
        {
            return (get_kth_element(A, m, B, n, len/2) + get_kth_element(A, m, B, n, len/2 + 1))/2;
        }
    }
    
    double get_kth_element(int A[], int m, int B[], int n, int k)
    {
        if (m > n)
        {
            return get_kth_element(B, n, A, m, k);
        }
        
        if (m == 0)
        {
            return B[k - 1];
        }
        
        if (k == 1)
        {
            return min(A[0], B[0]);
        }
        
        int aPos = min(m, k / 2);
        int bPos = k - aPos;
        
        if (A[aPos - 1] < B[bPos - 1])
        {
            return get_kth_element(A + aPos, m - aPos, B, n, k - aPos);
        }
        else if (A[aPos - 1] > B[bPos - 1])
        {
            return get_kth_element(A, m, B + bPos, n - bPos, k - bPos);
        }
        else
        {
            return A[aPos - 1];
        }
    }
};
