class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<int> solution;
        vector<vector<int> > result;
        combinationSumHelper(0, target, num, solution, result);
        
        return result;
    }
    
    void combinationSumHelper(int pos, int target, const vector<int> &num, vector<int> &sol, vector<vector<int> > &res)
    {
        if (target == 0)
        {
            res.push_back(sol);
            return;
        }
        
        for (int i = pos; i < num.size() && target >= num[i]; i++)
        {
            if (num[i] == num[i-1] && i > pos)
            {
                continue;
            }
            
            sol.push_back(num[i]);
            combinationSumHelper(i + 1, target - num[i], num, sol, res);
            sol.pop_back();
        }
    }
};
