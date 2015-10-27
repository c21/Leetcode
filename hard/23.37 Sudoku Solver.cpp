/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red.
*/

struct node
{
	int x;
	int y;
};


class Solution
{

	public:

	void solveSudoku(vector<vector<char> >& board) 
	{
		vector<node> array = vector<node>();

		for(int i = 0; i < board.size(); i++)
		{
			for(int j = 0; j < board[i].size(); j++)
			{
				if(board[i][j] == '.')
				{
					node s;
					s.x = i;
					s.y = j;
					array.push_back(s);
				}
			}
		}

		solve(board, array, 0);		
	}

	bool solve(vector<vector<char> >& board, vector<node>& array, int k)
	{
		if(k == array.size())
		{
			return true;
		}	
		else
		{
			for(int i = 1; i <= 9; i++)
			{
				int x = array[k].x;
				int y = array[k].y;
				board[x][y] = i+'0';
				if(!check(board, x, y))
				{
					board[x][y] = '.';	
				}
				else 
				{		
					if(!solve(board, array, k+1))
						board[x][y] = '.';
					else
						return true;
				}	
			}
			return false;	
		}
	}

	bool check(vector<vector<char> >& board, int x, int y)
	{
		// check row
		int flag[10];
		memset(flag, 0, sizeof(flag));
		for(int j = 0; j < board[x].size(); j++)
		{	
			if(board[x][j] != '.')
			{
				flag[board[x][j]-'0']++;
				if(flag[board[x][j]-'0'] > 1)
					return false;
			}	
		}	

		memset(flag, 0, sizeof(flag));
		// check col
		for(int i = 0; i < board.size(); i++)
    {
      if(board[i][y] != '.')
      {
        flag[board[i][y]-'0']++;
        if(flag[board[i][y]-'0'] > 1)
          return false;
      }
    }		

		// check box
		memset(flag, 0, sizeof(flag));
		int x1 = x/3*3;
		int y1 = y/3*3;
		for(int i = x1; i <= x1+2; i++)
		{
			for(int j = y1; j <= y1+2; j++)
			{
				if(board[i][j] != '.')
				{
					flag[board[i][j]-'0']++;
					if(flag[board[i][j]-'0'] > 1)
						return false;
				}
			}
		}		
		return true;	
	}	
};

/*
  枚举
  1.记录所有未填的位置，依次从1-9枚举
  2.填完一个位置后，检查所在行，列，方块是否有错
  3.如果没有错，就枚举下一个位置，否则尝试枚举该位置的其他情况
*/
