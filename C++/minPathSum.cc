class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ROW = grid.size();
        int COL = grid[0].size();
        
        if (ROW == 0 || COL == 0)
        {
            return 0;
        }
        
        int dp[ROW][COL];
        
        dp[0][0] = grid[0][0];
        
        for (int i = 1; i < ROW; i++)
        {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        for (int j = 1; j < COL; j++)
        {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        for (int i = 1; i < ROW; i++)
        {
            for (int j = 1; j < COL; j++)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[ROW-1][COL-1];
    }
};