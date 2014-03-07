class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = S.size();
        int N = 1 << len;
        
        sort(S.begin(), S.end());
        
        vector<vector<int> > result;
        
        for (int i = 0; i < N; i++)
        {
            vector<int> sub;
            for (int j = 0; j < len; j++)
            {
                if ((i >> j) & 1)
                {
                    sub.push_back(S[j]);
                }
            }
            result.push_back(sub);
        }
        
        return result;
    }
};