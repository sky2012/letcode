class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ROW = obstacleGrid.size();
        int COL = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1 || ROW == 0 || COL == 0)
        {
            return 0;
        }
        
        int dp[ROW][COL];
        dp[0][0] = 1;
        
        for (int i = 1; i < ROW; i++)
        {
            dp[i][0] = ((obstacleGrid[i][0] == 0) ? dp[i-1][0] : 0);
        }
        
        for (int j = 1; j < COL; j++)
        {
            dp[0][j] = ((obstacleGrid[0][j] == 0) ? dp[0][j-1] : 0);
        }
        
        for (int i = 1; i < ROW; i++)
        {
            for (int j = 1; j < COL; j++)
            {
                dp[i][j] = ((obstacleGrid[i][j] == 0) ? (dp[i-1][j] + dp[i][j-1]) : 0);
            }
        }
        
        return dp[ROW-1][COL-1];
    }
};