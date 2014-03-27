class Solution {
public:
    const string keymap[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        letterCombinationsHelper(digits, 0, "", res);
        return res;
    }
    
    void letterCombinationsHelper(string digits, int pos, string word, vector<string> &result)
    {
        if (pos == digits.size())
        {
            result.push_back(word);
            return;         
        }
        
        int index = digits[pos] - '2';
        for (int i = 0; i < keymap[index].size(); i++)
        {
            word.push_back(keymap[index][i]);
            letterCombinationsHelper(digits, pos + 1, word, result);
            word.pop_back();
        }
    }
};