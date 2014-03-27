#include <iostream>

using namespace std;

void DFS(vector<vector<int> > &board, int i, int j)
{
	int ROW = board.size();
	int COL = board[0].size();
	
	if (i >= 0 && i < ROW && j >= 0 && j < COL && board[i][j] == 1)
	{
		int temp = board[i][j];
		board[i][j] = -1;
		DFS(board, i - 1, j);
		DFS(board, i + 1, j);
		DFS(board, i, j - 1);
		DFS(board, i, j + 1);
		board[i][j] = temp;
	}
}

int numOfIslands(vector<vector<int> > &board)
{
	int count = 0;
	int ROW = board.size();
	int COL = board[0].size();
	
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			count++;
			DFS(board, i, j);
		}
	}
	
	return count;
}
		