/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/


class Solution 
{
	public:

	int minimumTotal(vector<vector<int> >& triangle) 
	{
		vector<int> result = vector<int>();
		for(int i = triangle.size()-1; i >= 0; i--)
		{
			if(i == triangle.size()-1)
			{
				for(int j = 0; j < triangle[i].size(); j++)
					result.push_back(triangle[i][j]);
			}
			else
			{
				for(int j = 0; j < triangle[i].size(); j++)
				{
					result[j] = min(result[j],result[j+1])+triangle[i][j];
				}
			}
		}
		return result[0];
		
	}


};

/*
  动态规划。
  设f(m,n)为元素t(m,n)的最小路径和，则f(m,n) = min(f(m+1,n),f(m+1,n+1))+t(m,n).
*/
