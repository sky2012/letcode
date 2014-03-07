class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int num = strs.size();
        
        if (num == 0)
        {
            return "";
        }
        
        string firstStr = strs[0];
        int len = firstStr.size();
        
        for (int i = 0; i < len; i++)
        {
            for (int j = 1; j < num; j++)
            {
                if (i == strs[j].size() || strs[0][i] != strs[j][i])
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};