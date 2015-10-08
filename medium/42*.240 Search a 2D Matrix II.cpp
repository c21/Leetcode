/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

class Solution 
{

	public:

	
	bool searchMatrix(vector<vector<int>>& matrix, int target) 
	{
		int row = matrix.size()-1;
		int col = 0;

	
		while(row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size())
		{
			if(matrix[row][col] == target)
				return true;
			else if(matrix[row][col] < target)
			{
				col++;	
			}	
			else
			{
				row--;
			}
		}		
		return false;	
	}


			
};

/*
  这题没有做出来，看了答案发现是O(m+n)的方法：
  从左下角a[i][j](a[n][0])开始搜索，如果a[i][j] < target, 那么第i行第j列左上的部分都比target小，j++
  如果a[i][j] > target, 那么第i行第j列右下的部分都比target大，i--.
*/
