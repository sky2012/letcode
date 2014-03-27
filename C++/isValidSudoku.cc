class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ROW = board.size();
        int COL = board[0].size();
        
        if (ROW == 0 || COL == 0 || ROW % 3 != 0 || COL % 3 != 0)
        {
            return false;
        }
        
        for (int i = 0; i < ROW; i++)
        {
            bool numMap[10] = {false};
            for (int j = 0; j < COL; j++)
            {
                if (board[i][j] != '.')
                {
                    int digit = board[i][j] - '0';
                
                    if (numMap[digit])
                    {
                        return false;
                    }
                    
                    numMap[digit] = true;
                }
            }
        }
        
        for (int j = 0; j < COL; j++)
        {
            bool numMap[10] = {false};
            for (int i = 0; i < ROW; i++)
            {
                if (board[i][j] != '.')
                {
                    int digit = board[i][j] - '0';
                
                    if (numMap[digit])
                    {
                        return false;
                    }
                    
                    numMap[digit] = true;
                }
            }
        }
        
        for (int i = 0; i < ROW; i++)
        {
            bool numMap[10] = {false};
            for (int j = 0; j < COL; j++)
            {
                int row = i / 3 * 3 + j / 3;
                int col = i % 3 * 3 + j % 3;
                
                if (board[row][col] != '.')
                {
                    int digit = board[row][col] - '0';
                
                    if (numMap[digit])
                    {
                        return false;
                    }
                    
                    numMap[digit] = true;
                }
            }
        }
        return true;
    }
};