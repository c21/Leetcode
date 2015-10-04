/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

class Solution 
{

	public:

    	int uniquePaths(int m, int n) 
	{
		int record[110][110];

		record[1][1] = 1;
		for(int i = 1; i <= m; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(!(i == 1 && j == 1))
				{
					record[i][j] = 0;
					if(j-1 >= 1)
						record[i][j] += record[i][j-1];
					if(i-1 >= 1)
						record[i][j] += record[i-1][j];
				}
			}
		}			
       		return record[m][n]; 

    	}

};

/*
  动态规划。
  设f(m, n)为m*n的不同路径数
  f(m, n) = f(m, n-1) + f(m-1, n).
*/
