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