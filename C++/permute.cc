class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        permuteHelper(num, 0, res);
        return res;
    }
    
    void permuteHelper(vector<int> &num, int pos, vector<vector<int> > &result)
    {  
        if (pos == num.size())
        {
            result.push_back(num);
        }
        
        for (int i = pos; i < num.size(); i++)
        {
            swap(num[i], num[pos]);
            permuteHelper(num, pos + 1, result);
            swap(num[i], num[pos]);
        }
    }
};