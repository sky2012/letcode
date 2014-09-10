class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        generateParenthesisHelper(n, n, "", result);
        return result;
    }
    
    void generateParenthesisHelper(int left, int right, string par, vector<string> &result)
    {
        if (left == 0 && right == 0)
        {
            result.push_back(par);
        }
        
        if (left > 0)
        {
            generateParenthesisHelper(left - 1, right, par + '(', result);
        }
        
        if (right > left)
        {
            generateParenthesisHelper(left, right - 1, par + ')', result);
        }
    }
};