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
        
        int len = strs[0].size();
        
        for (int pos = 0; pos < len; pos++)
        {
            for (int index = 1; index < num; index++)
            {
                if (pos == strs[index].size() || strs[index][pos] != strs[0][pos])
                {
                    return strs[0].substr(0, pos);
                }
            }
            
        }
        
        return strs[0];
    }
};