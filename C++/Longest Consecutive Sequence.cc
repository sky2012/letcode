class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        
        if (len <= 1)
        {
            return len;
        }
        
        sort(num.begin(), num.end());
        
        int count = 1;
        int maxCount = 1;
        
        for (int i = 1; i < len; i++)
        {
            int diff = num[i] - num[i-1];
            
            if (diff == 1)
            {
                count++;
                
                if (maxCount < count)
                {
                    maxCount = count;
                } 
            }
            else if (diff == 0)
            {
                continue;
            }
            else
            {
                count = 1;
            }
        }
        
        return maxCount;
    }
};