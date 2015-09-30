/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.  
*/
class Solution 
{

	public:

    	bool isValidSudoku(vector<vector<char> >& board) 
	{

		int r[10];
		
		// check each row
		for(int i = 0; i < 9; i++)
		{
			memset(r, 0, sizeof(r));	
			for(int j = 0; j < 9; j++)
			{
				if(board[i][j] != '.')
				{
					r[board[i][j]-'0']++;
					if(r[board[i][j]-'0'] > 1)
						return false;
				}
			}	
		}	

		// check each column
		for(int i = 0; i < 9; i++)
                {
                        memset(r, 0, sizeof(r));
                        for(int j = 0; j < 9; j++)
                        {
				if(board[j][i] != '.')
                                {
                                	r[board[j][i]-'0']++;
                                	if(r[board[j][i]-'0'] > 1)
                                        	return false;
				}
                        }
                }

		// check each box
		for(int a = 0; a <= 6; a = a+3)
		{
			for(int b = 0; b <= 6; b = b+3)
			{
				memset(r, 0, sizeof(r));	
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						if(board[a+i][b+j] != '.')
                                		{
							r[board[a+i][b+j]-'0']++;
							if(r[board[a+i][b+j]-'0'] > 1)
								return false;	
						}
					}
				}			
			}
		}		

		return true;	
    	}

};

/*
  模拟
*/
