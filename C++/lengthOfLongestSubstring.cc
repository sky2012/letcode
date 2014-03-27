class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        
        if (len <= 1)
        {
            return len;
        }
        
        int begin = 0;
        int current = 0;
        int maxLen = 0;
        bool charTable[256] = {false};
        
        while (current < len)
        {
            if (charTable[s[current]])
            {
                maxLen = max(maxLen, current - begin);
                while (s[current] != s[begin])
                {
                    charTable[s[begin]] = false;
                    begin++;
                }
                
                begin++;
            }
            else
            {
                charTable[s[current]] = true;
            }
            
            current++;
        }
        
        maxLen = max(maxLen, current - begin);
        return maxLen;
    }
};