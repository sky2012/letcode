class Solution {
public:
    
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<bool> > visit(board.size(), vector<bool>(board[0].size(), false));
        
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (dfs(board, visit, i, j, word))
                {
                    return true;
                }
            }
        }
        
        return false;               
    }
    
    bool dfs(vector<vector<char> > &board, vector<vector<bool> > &visited, int row, int col, string word)
    {       
        if (row < 0 || row >= board.size() || col < 0 || col > board[0].size())
        {
            return false;
        }
        
        if (word.size() == 0)
        {
            return true;
        }
        
        if (visited[row][col] || board[row][col] != word[0])
        {
            return false;
        }
        
        visited[row][col] = true;
        string s = word.substr(1, word.size());
        
        if (dfs(board, visited, row - 1, col, s) 
        || dfs(board, visited, row, col -1 , s)
        || dfs(board, visited, row + 1, col, s)
        || dfs(board, visited, row, col + 1, s))
        {
            return true;
        }
        else
        {
            visited[row][col] = false;
            return false;
        }         
    }
};