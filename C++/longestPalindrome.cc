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
            string oddPali = expandCenter(s, i, i);
            
            if (result.length() < oddPali.length())
            {
                result = oddPali;
            }
            
            string evenPali = expandCenter(s, i, i+1);
            
            if (result.length() < evenPali.length())
            {
                result = evenPali;
            }
        }
        
        return result;
    }
    
    string expandCenter(string str, int left, int right)
    {
        
        while (left >= 0 && right < str.size() && str[left] == str[right])
        {
            left--;
            right++;
        }
        
        return str.substr(left + 1, right - left - 1);
    }
};