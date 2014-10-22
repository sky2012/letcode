class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        
        while (true)
        {
            char *h = haystack;
            char *n = needle;
            
            while (*n != '\0' && *h == *n)
            {
                h++;
                n++;
            }
            
            if (*n == '\0')
            {
                return haystack;
            }
            
            if (*h == '\0')
            {
                return NULL;
            }
            
            haystack++;
        }
    }
};
