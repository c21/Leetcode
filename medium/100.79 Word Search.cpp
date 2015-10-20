/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution 
{

	public:

	vector<vector<int> > record;

	int dic_x[4] = {0, 1, 0, -1};
	int dic_y[4] = {1, 0, -1, 0};

	bool exist(vector<vector<char> >& board, string word) 
	{
		if(word.length() == 0 || board.size() == 0 || board[0].size() == 0)
			return false;
	
		record = vector<vector<int> >();
		
		for(int i = 0; i < board.size(); i++)
		{
			record.push_back(vector<int>());
			for(int j = 0; j < board[i].size(); j++)
				record[i].push_back(0);
		}
		for(int i = 0; i < board.size(); i++)
		{
			for(int j = 0; j < board[i].size(); j++)
			{
				if(board[i][j] == word[0])
				{
					record[i][j] = 1;
					if(search(board, word, 1, i, j))
						return true;		
					record[i][j] = 0;
				}
			}
		}	
		return false;			
	}

	bool search(vector<vector<char> >& board, string& word, int begin, int x, int y)
	{
		if(begin == word.size())
			return true;
		for(int i = 0; i < 4; i++)
		{
			int new_x = x+dic_x[i];
			int new_y = y+dic_y[i];
			if(new_x >= 0 && new_x < board.size() && new_y >= 0 && new_y < board[0].size()
				&& record[new_x][new_y] == 0 && word[begin] == board[new_x][new_y])
			{
				record[new_x][new_y] = 1;
				if(search(board, word, begin+1, new_x, new_y))
					return true;
				record[new_x][new_y] = 0;
			}	
		}	
		return false;	
	}
};

/*
  深度优先搜索
*/
