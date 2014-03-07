public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        int ROW = matrix.length;
        int COL = matrix[0].length;
        
        if (target < matrix[0][0] || target > matrix[ROW - 1][COL - 1])
        {
            return false;
        }
        
        int i = 0;
        int j = COL - 1;
        
        while (i < ROW && j >= 0)
        {
            if (matrix[i][j] < target)
            {
                i++;
            }
            else if (matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
}