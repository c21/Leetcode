/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution 
{

	public:

    	int minPathSum(vector<vector<int>>& grid) 
	{
		vector<vector<int> > record = vector<vector<int> >();
		for(int i = 0; i < grid.size(); i++)
		{
			record.push_back(vector<int>());
			for(int j = 0; j < grid[i].size(); j++)
				record[i].push_back(0);
		}
		for(int i = grid.size()-1; i >= 0; i--)
		{
			for(int j = grid[i].size()-1; j >= 0; j--)
			{
				int r1 = -1;
				int r2 = -1;
				if(j+1 < grid[i].size())
					r1 = record[i][j+1];
				if(i+1 < grid.size())
					r2 = record[i+1][j];
				if(r1 == -1 && r2 == -1)
					record[i][j] = grid[i][j];
				else if(r1 == -1 && r2 != -1)
					record[i][j] = grid[i][j] + r2;
				else if(r1 != -1 && r2 == -1)
					record[i][j] = grid[i][j] + r1;
				else
					record[i][j] = grid[i][j] + min(r1,r2);			
			}
		}
		return record[0][0];	
    	}

};

/*
  动态规划。
  设f(m, n)为m*n格的最小路径和
  f(m,n) = grid[m][n] + min(f(m-1,n),f(m,n-1)).
*/
