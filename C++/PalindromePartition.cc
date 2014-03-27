class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> vect;
        vector<vector<string> > result;
        partitionHelper(s, 0, vect, result);
        return result;
    }
    
    bool isPalindrome(string s, int begin, int end)
    { 
        while (begin < end)
        {
            if (s[begin++] != s[end--])
            {
                return false;
            }
        }
        
        return true;
    }
    
    void partitionHelper(string s, int pos, vector<string> &seg, vector<vector<string> > &res)
    {
        if (pos == s.size())
        {
            res.push_back(seg);
            return;
        }
        
        for (int i = pos; i < s.size(); i++)
        {
            if (isPalindrome(s, pos, i))
            {
                seg.push_back(s.substr(pos, i - pos + 1));
                partitionHelper(s, i + 1, seg, res);
                seg.pop_back();
            }
        }
    }
};