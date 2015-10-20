/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution 
{

	public:

	int dic_x[4] = {0, 1, 0, -1};
	int dic_y[4] = {1, 0, -1, 0};

	vector<int> spiralOrder(vector<vector<int> >& matrix) 
	{
		vector<int> result = vector<int>();
		if(matrix.size() == 0)
			return result;
		vector<vector<int> > record = vector<vector<int> >();
		for(int i = 0; i < matrix.size(); i++)
		{
			record.push_back(vector<int>());
			for(int j = 0; j < matrix[i].size(); j++)
				record[i].push_back(0);
		}
		int d = 0;
		int i = 0;
		int x = 0, y = 0;
		while(1)
		{
			result.push_back(matrix[x][y]);
			record[x][y] = 1;
			int new_x = x+dic_x[d];
			int new_y = y+dic_y[d];
			if(!(new_x >= 0 && new_x < matrix.size() && new_y >= 0 && new_y < matrix[0].size() && 
				record[new_x][new_y] == 0))
			{
				d = (d+1)%4;
				new_x = x+dic_x[d];
				new_y = y+dic_y[d];
				if(!(new_x >= 0 && new_x < matrix.size() && new_y >= 0 && new_y < matrix[0].size() &&
                                record[new_x][new_y] == 0))
				{
					break;
				}	
			}		
			x = new_x;
			y = new_y;	
		}
		return result;						
	}

};

/*
  模拟。
*/
