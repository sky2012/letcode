public class Solution {
    public boolean exist(char[][] board, String word) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ROW = board.length;
        int COL = board[0].length;
        
        if (ROW == 0 || COL == 0)
        {
            return false;
        }
        
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (board[i][j] == word.charAt(0))
                {
                    if (DFS(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    public boolean DFS(char[][] board, String word, int i, int j, int pos)
    {
        if (pos == word.length())
        {
            return true;
        }
        
        int ROW = board.length;
        int COL = board[0].length;
        
        if (i >= 0 && i < ROW && j >= 0 && j < COL && board[i][j] == word.charAt(pos))
        {
            char temp = board[i][j];
            board[i][j] = '.';
            pos++;
            
            if (DFS(board, word, i - 1, j, pos) || DFS(board, word, i + 1, j, pos)
            || DFS(board, word, i, j - 1, pos) || DFS(board, word, i, j + 1, pos))
            {
                return true;
            }
            
            board[i][j] = temp;
        }
        
        return false;
    }
}
