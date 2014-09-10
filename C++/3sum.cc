class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int size = num.size();
        vector<vector<int> > result;
        
        if (size <= 2)
        {
            return result;
        }
        
        sort(num.begin(), num.end());
        
        for (int i = 0; i < size - 1; i++)
        {
            if (i > 0 && num[i] == num[i - 1])
            {
                continue;
            }
            
            int j = i + 1;
            int k = size - 1;
            
            while (j < k)
            {
                int sum = num[i] + num[j] + num[k];
                
                if (sum == 0)
                {
                    vector<int> trip({num[i], num[j], num[k]});
                    result.push_back(trip);
                    do
                    {
                        j++;
                    } while (j < k && num[j - 1] == num[j]);
                    
                    do
                    {
                        k--;
                    } while (j < k && num[k] == num[k + 1]);
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        
        return result;
    }
};
