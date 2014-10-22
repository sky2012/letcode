class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int row = board.size();
        
        if (row == 0 || row % 3 != 0)
        {
            return false;
        }
        
        int col = board[0].size();
        
        if (col == 0 || col % 3 != 0)
        {
            return false;
        }
        
        for (int i = 0; i < row; i++)
        {
            bool rowMap[9] = {false};
            bool colMap[9] = {false};
            bool digMap[9] = {false};
            
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] != '.')
                {
                    int index = board[i][j] - '1';
                    if (rowMap[index])
                    {
                        return false;
                    }
                    rowMap[index] = true;
                }
                
                if (board[j][i] != '.')
                {
                    int index = board[j][i] - '1';
                    if (colMap[index])
                    {
                        return false;
                    }
                    colMap[index] = true;
                }
                
                int r = i / 3 * 3 + j / 3;
                int c = i % 3 * 3 + j % 3;
                if (board[r][c] != '.')
                {
                    int index = board[r][c] - '1';
                    if (digMap[index])
                    {
                        return false;
                    }
                    digMap[index] = true;
                }
            }
        }
        
        return true;
    }
};
