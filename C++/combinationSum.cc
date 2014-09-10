class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> solution;
        vector<vector<int> > result;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(0, target, candidates, solution, result);
        
        return result;
    }
    
    void combinationSumHelper(int pos, int target, vector<int> candidates, vector<int> &sol, vector<vector<int> > &res)
    {
        if (target == 0)
        {
            res.push_back(sol);
            return;
        }
        
        for (int i = pos; target >= candidates[i] && i < candidates.size(); i++)
        {
            sol.push_back(candidates[i]);
            combinationSumHelper(i, target - candidates[i], candidates, sol, res);
            sol.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> com;
        combinationSumRe(candidates, target, 0, com, res);
        return res;
    }

    void combinationSumRe(const vector<int> &num, int target, int start, vector<int> &com, vector<vector<int>> &res)
    {
        if (target == 0) {
            res.push_back(com);
            return;
        }
        for (int i = start; i < num.size() && target >= num[i]; ++i) {
            com.push_back(num[i]);
            combinationSumRe(num, target-num[i], i, com, res);
            com.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        
        if (candidates.empty())
        {
            return result;
        }
        
        sort(candidates.begin(), candidates.end());
        
        int last = candidates.back();
        if (target == last)
        {
            result.push_back(vector<int>(1, last));
        }
        else if (target > last)
        {
            vector<vector<int> > rest = combinationSum(candidates, target - last);
            
            for (int i = 0; i < rest.size(); i++)
            {
                rest[i].push_back(last);
                result.push_back(rest[i]);
            }
        }
        
        
        vector<int> candidatesLeaveLast(candidates.begin(), candidates.end() - 1);
        vector<vector<int> > leaveLastResult = combinationSum(candidatesLeaveLast, target);
        
        result.insert(result.end(), leaveLastResult.begin(), leaveLastResult.end());
        
        return result;   
        
    }
};
