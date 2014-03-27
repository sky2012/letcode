class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ROW = matrix.size();
        int COL = matrix[0].size();
        
        if (ROW == 0 || COL == 0)
        {
            return 0;
        }
        
        int maxArea = 0;
        vector<int> hist(COL, 0);
        
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (matrix[i][j] == '1')
                {
                    hist[j]++;
                }
                else
                {
                    hist[j] = 0;
                }
            }
            
            maxArea = max(maxArea, maxRectangleInHist(hist));
        }
        
        return maxArea;
    }
    
    int maxRectangleInHist(vector<int> &hist)
    {
        int len = hist.size();
        
        if (len == 0)
        {
            return 0;
        }
        
        int maxArea = 0;
        hist.push_back(0);
        stack<int> stk;
        
        for (int i = 0; i <= len; i++)
        {
            int count = 0;
            
            while (!stk.empty() && hist[i] < stk.top())
            {
                count++;
                maxArea = max(maxArea, stk.top() * count);
                stk.pop();
            }
            
            while (count > 0)
            {
                count--;
                stk.push(hist[i]);
            }
            
            stk.push(hist[i]);
        }
        
        return maxArea;
    }
};