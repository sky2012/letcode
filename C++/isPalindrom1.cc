class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        
        if (len == 0)
        {
            return true;
        }
        
        string temp(s);
        
        for (int i = 0; i < len; i++)
        {
            if (isupper(temp[i]))
            {
                temp[i] = tolower(temp[i]);
            }
        }
        
        int front = 0;
        int back = len - 1;
        
        while (front < back)
        {
            if (isalnum(temp[front]) && isalnum(temp[back]))
            {
                if (temp[front] != temp[back])
                {
                    return false;
                }
                
                front++;
                back--;
            }
            
            if (!isalnum(temp[front]))
            {
                front++;
            }
            
            if (!isalnum(temp[back]))
            {
                back--;
            }
        }
        
        return true;
        
    }
};