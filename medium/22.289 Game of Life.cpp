/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/

class Solution {
public:
    int dir_x[8] = {0, -1, -1, -1, 0, 1, 1, 1};
	  int dir_y[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

  	void gameOfLife(vector<vector<int>>& board) 
  	{
  		for(int i = 0; i < board.size(); i++)
  		{
  			for(int j = 0; j < board[i].size(); j++)
  			{
  				int c_live = 0;
  				int c_dead = 0;
  				for(int k = 0; k < 8; k++)
  				{
  					if(i+dir_x[k] >= 0 && i+dir_x[k] < board.size()
  						&& j+dir_y[k] >= 0 && j+dir_y[k] < board[i].size())
  					{
  						if(board[i+dir_x[k]][j+dir_y[k]] == 1 || board[i+dir_x[k]][j+dir_y[k]] == -1)
  							c_live++;
  						else if(board[i+dir_x[k]][j+dir_y[k]] == 0 || board[i+dir_x[k]][j+dir_y[k]] == 2)
  							c_dead++;	
  					}
  				}	
  				if((board[i][j] == 1 && c_live < 2) || (board[i][j] == 1 && c_live > 3))
  				{
  					board[i][j] = -1;
  				}
  				else if(board[i][j] == 0 && c_live == 3)
  				{
  					board[i][j] = 2;
  				}
  			}
  		}	
          
  		for(int i = 0; i < board.size(); i++)
  		{
  			for(int j = 0; j < board[i].size(); j++)
  			{
  				if(board[i][j] == 2)
  					board[i][j] = 1;
  				else if(board[i][j] == -1)
  					board[i][j] = 0;
  			}
  		}
    }
};

/*
  将活的变为死的，先赋值成-1
  将死的变为活的，先赋值成2
  然后将-1改成0，将2改成1
*/
