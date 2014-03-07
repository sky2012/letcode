class Solution {
public:
    
    vector<string> result;
    const string keymap[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        result.clear();
        letterCombinationsHelper(digits, 0, "");
        return result;
    }
    
    void letterCombinationsHelper(string digits, int pos, string str)
    {
        if (pos == digits.size())
        {
            result.push_back(str);
            return;         
        }
        
        int index = digits[pos] - '2';
        for (int i = 0; i < keymap[index].size(); i++)
        {
            letterCombinationsHelper(digits, pos + 1, str + keymap[index][i]);
        }
    }
};