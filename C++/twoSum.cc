class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (numbers.size() < 2)
        {
                exit(1);
        }
       
        vector<int>::iterator front;
        vector<int>::iterator back;
        vector<int> result;
        
        
        for (front = numbers.begin(); front != numbers.end(); front++)
        {
            back = find(front + 1, numbers.end(), target - *front);
            
            if (back != numbers.end())
            {
                result.push_back(front - numbers.begin() + 1);
                result.push_back(back - numbers.begin() + 1);
                return result;
            }
        }
    }
};