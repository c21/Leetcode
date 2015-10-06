/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution 
{


	public:

    	void setZeroes(vector<vector<int> >& matrix) 
	{
		if(!(matrix.size() == 0 || matrix[0].size() == 0))	
        	{
			int first_row = -1;
			int first_column = -1;
			for(int i = 0; i < matrix[0].size(); i++)
			{
				if(matrix[0][i] == 0)
				{
					first_row = 0;
					break;
				}
			}		
			for(int i = 0; i < matrix.size(); i++)
                        {
                                if(matrix[i][0] == 0)
                                {
                                        first_column = 0;
                                        break;
                                }
                        }

			for(int i = 0; i < matrix.size(); i++)
			{
				for(int j = 0; j < matrix[i].size(); j++)
				{
					if(matrix[i][j] == 0)
					{
						matrix[i][0] = 0;
						matrix[0][j] = 0;
					}
				}
			}

			for(int i = 1; i < matrix[0].size(); i++)
			{
				if(matrix[0][i] == 0)
				{
					for(int j = 0; j < matrix.size(); j++)
						matrix[j][i] = 0;
				}
			}
			for(int i = 1; i < matrix.size(); i++)
			{
				if(matrix[i][0] == 0)
				{
					for(int j = 0; j < matrix[i].size(); j++)
						matrix[i][j] = 0;
				}
			}
			if(first_row == 0)
			{
				for(int i = 0; i < matrix[0].size(); i++)
					matrix[0][i] = 0;
			}	
			if(first_column == 0)
			{
				for(int i = 0; i < matrix.size(); i++)
					matrix[i][0] = 0;
			}
		}

    	}

};

/*
  这题没想出来，看了答案发现关键是要知道：当遇到一个0，它所在的行和列都要变为0.
  这样，遇到一个0，记录所在的行和列，等到遍历完所有的元素，再根据记录的行和列赋为0.
  可以使用第一行和第一列来记录，不需要额外空间，只需要一开始先记录第一行和第一列是否需要变为0即可。
*/
