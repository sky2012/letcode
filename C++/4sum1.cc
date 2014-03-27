class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = num.size();
        vector<vector<int> > result;
        vector<int> fourVect;
        
        if (size <= 3)
        {
            return result;
        }
        
        sort(num.begin(), num.end());
        
        for (int i = 0; i < size - 3; i++)
        {
            for (int j = i + 1; j < size - 2; j++)
            {
                int m = j + 1;
                int n = size - 1;
                
                while (m < n)
                {
                    int sum = num[i] + num[j] + num[m] + num[n];
                    
                    if (sum == target)
                    {
                        fourVect.clear();
                        fourVect.push_back(num[i]);
                        fourVect.push_back(num[j]);
                        fourVect.push_back(num[m]);
                        fourVect.push_back(num[n]);
                        if (find(result.begin(), result.end(), fourVect) == result.end())
                        {
                            result.push_back(fourVect);
                        }
                        m++;
                        n--;
                    }
                    else if (sum < target)
                    {
                        m++;
                    }
                    else
                    {
                        n--;
                    }
                }
            }
        }
        
        return result;
    }
};