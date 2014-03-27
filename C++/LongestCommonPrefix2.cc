class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = strs.size();
        string result;
        
        if (size == 0)
        {
            return result;
        }
        
        string firstStr = strs[0];
        int len = firstStr.size();
        
        for (int i = 0; i < len; i++)
        {
            for (int j = 1; j < size; j++)
            {
                if (strs[j].size() == i || firstStr[i] != strs[j][i])
                {
                    return firstStr.substr(0, i);
                }
            }
        }
        
        return firstStr;
    }
};