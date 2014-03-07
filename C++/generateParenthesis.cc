class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> par;
        genParHelper(n, n, "", par);
        return par;
    }
    
    void genParHelper(int left, int right, string str, vector<string> &result)
    {
       if (left == 0 && right == 0)
       {
           result.push_back(str);
       }
       
       if (left > 0)
       {
           genParHelper(left - 1, right, str + '(', result);
       }
       
       if (right > left)
       {
           genParHelper(left, right - 1, str + ')', result);
       }
    }
};