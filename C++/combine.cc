class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> solution;
        vector<vector<int> > result;
        
        combineHelper(n, k, 1, solution, result);
        return result;
    }
    
    void combineHelper(int n, int k, int pos, vector<int> &sol, vector<vector<int> > &res)
    {
        int len = sol.size();
        if (len == k)
        {
            res.push_back(sol);
            return;
        }
        
        for (int i = pos; i <= n - (k - len) + 1; i++)
        {
            sol.push_back(i);
            combineHelper(n, k, i + 1, sol, res);
            sol.pop_back();
        }
    }
};
