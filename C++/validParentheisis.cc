class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        
        if (len == 0)
        {
            return false;
        }
        
        stack<char> parStack;
        
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                parStack.push(s[i]);
            }
            else
            {
                if (parStack.empty())
                {
                    return false;
                }
                
                char stackTop = parStack.top();
                
                if (stackTop == '(' && s[i] == ')'
                 || stackTop == '[' && s[i] == ']'
                 || stackTop == '{' && s[i] == '}')
                 {
                     parStack.pop();
                 }
                 else
                 {
                     return false;
                 }   
            }
        }
        
        return parStack.empty();
    }
};