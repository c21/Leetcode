/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

class Solution 
{
  public:
  int dir_x[4] = {0, -1, 0, 1};
	int dir_y[4] = {-1, 0, 1, 0};
  vector<vector<char> > visit;
    
	int numIslands(vector<vector<char> >& grid) 
	{
		visit = vector<vector<char> >();
		for(int i = 0; i < grid.size(); i++)
		{
			visit.push_back(vector<char>());
			for(int j = 0; j < grid[i].size(); j++)
				visit[i].push_back(0);
		}
		
		int count = 0;
		for(int i = 0; i < grid.size(); i++)
		{
			for(int j = 0; j < grid[i].size(); j++)
			{
				if(grid[i][j] == '1' && visit[i][j] == 0)
				{
					count++;
					dfs_search(i, j, grid);		
				}
			}
		}		

		return count;	
	}


	void dfs_search(int a, int b, vector<vector<char> >& grid)
	{
		visit[a][b] = 1;
		for(int i = 0; i < 4; i++)
		{
			int new_x = a+dir_x[i];
			int new_y = b+dir_y[i];
			if(new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[new_x].size()
				&& grid[new_x][new_y] == '1' && visit[new_x][new_y] == 0)
			{
				dfs_search(new_x, new_y, grid);
			}
		}		
	}
};

/*
  深度优先搜索找连通分量。
*/
