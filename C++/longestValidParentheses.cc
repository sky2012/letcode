class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        
        if (len <= 1)
        {
            return 0;
        }
        
        int count = 0;
        int maxCount = 0;
        int parStack = 0;
        
        for (int i = 0; i < len; i++)
        {
            count++;
            
            if (s[i] == '(')
            {
                parStack++;
            }
            else
            {
                parStack--;
            }
            
            if (parStack == 0)
            {
                maxCount = max(maxCount, count);
            }
            
            if (parStack < 0)
            {
                count = 0;
                parStack = 0;
            }
        }
        
        parStack = 0;
        count = 0;
        
        for (int i = len - 1; i >= 0; i--)
        {
            count++;
            
            if (s[i] == ')')
            {
                parStack++;
            }
            else
            {
                parStack--;
            }
            
            if (parStack == 0)
            {
                maxCount = max(count, maxCount);
            }
            
            if (parStack < 0)
            {
                parStack = 0;
                count = 0;
            }
        }
        
        return maxCount;
    }
};