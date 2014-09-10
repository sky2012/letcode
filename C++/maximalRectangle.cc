class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int maxArea = 0;
        
        if (row == 0 || col == 0)
        {
            return 0;
        }
        
        vector<int> height(col, 0);
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == '0')
                {
                    height[j] = 0;
                }
                else
                {
                    height[j]++;
                }
            }
            
            maxArea = max(maxArea, getMaxRectangleHist(height));
        }
        
        return maxArea;
    }
    
    int getMaxRectangleHist(vector<int> &hist)
    {
        int len = hist.size();
        hist.push_back(0);
        
        if (len = 0)
        {
            return 0;
        }
        
        int result = 0;
        stack<int> heightStack;
        
        for (int i = 0; i <= len; i++)
        {
            int count = 0;
            while (!heightStack.empty() && heightStack.top() > hist[i])
            {
                count++;
                result = max(result, heightStack.top() * count);
                heightStack.pop();
            }
            
            while (count--)
            {
                heightStack.push(hist[i]);
            }
            
            heightStack.push(hist[i]);
        }
        
        return result;
    }
};
