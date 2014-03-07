class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = S.size();
        sort(S.begin(), S.end());
        
        set<vector<int> > result;
        int N = 1 << len;
        
        for (int i = 0; i < N; i++)
        {
            vector<int> sub;
            for (int j = 0; j < len; j++)
            {
                if (i >> j & 1)
                {
                    sub.push_back(S[j]);
                }
            }
            result.insert(sub);
        }
    
        vector<vector<int> > res(result.begin(), result.end());
        return res;
    }
};