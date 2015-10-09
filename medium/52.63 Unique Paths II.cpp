/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution 
{

	public:

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
	{
		if(obstacleGrid.size() == 0)
			return 0;
		
		vector<int> record = vector<int>();
                int count = 0;
		for(int i = 0; i < obstacleGrid[0].size(); i++)
			record.push_back(0);
		if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1] == 0)
			record[obstacleGrid[0].size()-1] = 1;
		for(int i = obstacleGrid.size()-1; i >= 0; i--)
		{
			for(int j = obstacleGrid[0].size()-1; j >= 0; j--)
			{
				if(obstacleGrid[i][j] == 1)
					record[j] = 0;
				else if(j != obstacleGrid[0].size()-1 && obstacleGrid[i][j] == 0)
				{
					record[j] += record[j+1];
				}			
			}
		}
		return record[0];
	}

};

/*
  动态规划。
  设f(m,n)为m*n的不同路径数。
  如果grid(m,n) = 1, f(m,n) = 0.
  如果grid(m,n) = 0, f(m,n) = f(m,n+1) + f(m+1,n).
*/
