class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        
        if (len == 0)
        {
            return "";
        }
        
        string result = s.substr(0, 1);
        for (int i = 0; i < len - 1; i++)
        {
            string odd = expandAroundCenter(s, i, i);
            
            if (odd.size() > result.size())
            {
                result = odd;
            }
            
            string even = expandAroundCenter(s, i, i + 1);
            
            if (even.size() > result.size())
            {
                result = even;
            }
        }
        
        return result;
    }
    
    string expandAroundCenter(string s, int begin, int end)
    {
        int len = s.size();
        
        while (begin >= 0 && end < len && s[begin] == s[end])
        { 
            begin--;
            end++;
        }
        
        return s.substr(begin + 1, end - begin - 1);
    }
};