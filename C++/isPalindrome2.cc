class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        
        if (len <= 1)
        {
            return true;
        }
        
        int i = 0;
        int j = len - 1;
        
        while (i < j)
        {
            if (isalnum(s[i]) && isalnum(s[j]))
            {
                if (tolower(s[i]) != tolower(s[j]))
                {
                    return false;
                }
                
                i++;
                j--;
            }
            else
            {
                if (!isalnum(s[i]))
                {
                    i++;
                }
                
                if (!isalnum(s[j]))
                {
                    j--;
                }
            }
        }
        
        return true;
    }
};