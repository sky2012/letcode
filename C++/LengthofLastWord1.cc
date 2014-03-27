class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = strlen(s);
        
        if (len == 0)
        {
            return 0;
        }
        
        int i = len - 1;
        
        while (!isalpha(s[i]) && i > 0)
        {
            i--;
        }
        
        int count = 0;
        
        while (isalpha(s[i]))
        {
            count++;
            i--;
            
            if (i < 0)
            {
                break;
            }
        }
        
        return count;
    }
};