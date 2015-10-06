/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

class Solution 
{

	public:

    	void rotate(vector<vector<int> >& matrix) 
	{
		int n = matrix.size()-1;
		for(int i = 0; i < matrix.size(); i++)
		{
			for(int j = 0; j < matrix[i].size()-i; j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[n-j][n-i];
				matrix[n-j][n-i] = tmp;	
			}
		}

		for(int i = 0; i < matrix.size()/2; i++)
		{
			for(int j = 0; j < matrix[i].size(); j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[n-i][j];
				matrix[n-i][j] = tmp;
			}
		}	
        

    	}

};

/*
  想要用常数空间进行顺时针90度旋转，可以先按照右对角线(/)翻转，再按照中线(-)翻转。
*/
