class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ROW = board.size();
        int COL = board[0].size();
        
        if (ROW == 0 || COL == 0)
        {
            return false;
        }
        
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (word[0] == board[i][j])
                {
                    if (BFS(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    bool BFS(vector<vector<char> > &board, string word, int i, int j, int pos)
    {
        if (word.size() == pos)
        {
            return true;
        }
        
        int ROW = board.size();
        int COL = board[0].size();
        
        if (i >= 0 && i < ROW && j >= 0 && j < COL && word[pos] == board[i][j])
        {
            char tempChar = board[i][j];
            board[i][j] = '.';
            pos++;
            
            if (BFS(board, word, i - 1, j, pos) || BFS(board, word, i + 1, j, pos)
             || BFS(board, word, i, j - 1, pos) || BFS(board, word, i, j + 1, pos))
             {
                 return true;
             }
             
             board[i][j] = tempChar;
        }
        
        return false;
    }
};