class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        
        if (len < 3)
        {
            return INT_MIN;
        }
        
        sort(num.begin(), num.end());
        int closestSum = num[0] + num[1] + num[2];
        
        for (int i = 0; i < len - 2; i++)
        {
            int j = i + 1;
            int k = len - 1;
        
            while (j < k)
            {
                int sum = num[i] + num[j] + num[k];
                if (target == sum)
                {
                    return sum;
                }
                
                if (abs(sum - target) < abs(closestSum - target))
                {
                    closestSum = sum;
                }
                
                if (target < sum)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        
        return closestSum;
    }
};