class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = num.size();
        
        if (size <= 2)
        {
            return 0;
        }
        
        sort(num.begin(), num.end());
        int closeSum = num[0] + num[1] + num[2];
        for (int i = 0; i < size - 2; i++)
        {
            int j = i + 1;
            int k = size - 1;
            
            while (j < k)
            {
                int sum = num[i] + num[j] + num[k];
                
                if (sum == target)
                {
                    return target;
                }
                
                if (abs(sum - target) < abs(closeSum - target))
                {
                    closeSum = sum;
                }
                
                if (sum > target)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        
        return closeSum;
    }
};