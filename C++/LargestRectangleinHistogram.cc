class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int len = height.size();
        
        if (len == 0)
        {
            return 0;
        }
        
        int maxArea = 0;
        height.push_back(0);
        stack<int> stk;
        
        for (int i = 0; i <= len; i++)
        {
            int count = 0;
            
            while (!stk.empty() && height[i] < stk.top())
            {
                count++;
                maxArea = max(maxArea, stk.top() * count);
                stk.pop();
            }
            
            while (count > 0)
            {
                count--;
                stk.push(height[i]);
            }
            
            stk.push(height[i]);
        }
        
        return maxArea;
    }
};