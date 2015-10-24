/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

#include <vector>
#include <utility>
#include <cstdio>
#include <queue>
using namespace std;



class Solution 
{

	public:

	void solve(vector<vector<char> >& board) 
	{
		if(board.size() == 0)
			return ;
/*		vector<vector<int> > visit = vector<vector<int> >();
		for(int i = 0; i < board.size(); i++)
		{
			visit.push_back(vector<int>());
			for(int j = 0; j < board[i].size(); j++)
			{
				if(board[i][j] == 'X')
				{
					visit[i].push_back(-1);
				}
				else
				{
					visit[i].push_back(0);
				}
			}
		}
*/		
//		printf("here\n");
		
			for(int j = 0; j < board[0].size(); j++)
			{
/*				if(visit[0][j] == 0)
				{
*/					search(0, j, board);	
/*				}	
				if(visit[board.size()-1][j] == 0)
				{
*/					search(board.size()-1, j, board);	
//				}
			}
			for(int j = 0; j < board.size(); j++)
			{
/*
				if(visit[j][0] == 0)
				{
*/					search(j, 0, board);
/*				}
				if(visit[j][board[0].size()-1] == 0)
				{
*/					search(j, board[0].size()-1, board);
//				}
			}
			

		for(int i = 0; i < board.size(); i++)
		{
			for(int j = 0; j < board[i].size(); j++)
                        {
                                if(board[i][j] == 'O')
                                {
					board[i][j] = 'X';
				}
				else if(board[i][j] == 'Y')
				{
					board[i][j] = 'O';
				}
			}
		}		
//		printf("here2\n");
	}	

	int dic_x[4] = {0, -1, 0, 1};
	int dic_y[4] = {-1, 0, 1, 0};
	void search(int x, int y, vector<vector<char> >& board)
	{

		queue<pair<int,int> > my_queue = queue<pair<int,int> >();
		if(board[x][y] == 'O')
			my_queue.push(make_pair(x, y));
		while(my_queue.size() > 0)
		{
			pair<int,int> p = my_queue.front();
			my_queue.pop();
			board[p.first][p.second] = 'Y';
			for(int i = 0; i < 4; i++)
			{
				int new_x = p.first + dic_x[i];
                        	int new_y = p.second + dic_y[i];
				if(new_x >= 0 && new_x < board.size() && new_y >= 0 && new_y < board[new_x].size()
                                && board[new_x][new_y] == 'O')
				{
					my_queue.push(make_pair(new_x, new_y));
				}
			}				
		}
	
	}
};


int main()
{
	Solution s;
	int x, y;
	scanf("%d %d", &x, &y);
	vector<vector<char> > board = vector<vector<char> >();
	for(int i = 0; i < x; i++)
	{
		board.push_back(vector<char>());
		for(int j = 1; j <= y; j++)
		{
			char ch[100];
			scanf("%s", &ch);
			board[i].push_back(ch[0]);	
		}	
	}		
	s.solve(board);
	for(int i = 0; i < x; i++)
	{
		for(int j = 0; j < y; j++)
			printf("%c ", board[i][j]);
		printf("\n");
	}
	return 0;
}

/*
  相当于搜索来确定和边界'O'相连的'O'.
  一开始用DFS搜索全图，run time error. 在网上查过之后好像是栈溢出。
  改用BFS, 超时。
  发现可以只搜边界就可以，通过。
*/
