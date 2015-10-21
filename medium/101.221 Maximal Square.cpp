/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/

class Solution 
{

	public:

	int maximalSquare(vector<vector<char> >& matrix) 
	{
		vector<vector<int> > record = vector<vector<int> >();
		for(int i = 0; i < matrix.size(); i++)
		{
			record.push_back(vector<int>());
			for(int j = 0; j < matrix[i].size(); j++)
				record[i].push_back(-1);	
		}			

		int max_s = 0;
		for(int i = 0; i < matrix.size(); i++)
		{
			for(int j = 0; j < matrix[i].size(); j++)
			{
				int x = get_max(matrix, record, i, j);	
				if(x > max_s)
					max_s = x;
			}
		}		

		return max_s;	
	}

	int get_max(vector<vector<char> >& matrix, vector<vector<int> >& record, int x, int y)
	{
		if(record[x][y] >= 0)
			return record[x][y];
		else
		{
			if(matrix[x][y] == '0')
			{
				record[x][y] = 0;
			}
			else
			{
				if(y+1 < matrix[x].size() && x+1 < matrix.size())
				{
					int k1 = get_max(matrix, record, x, y+1);
					int k2 = get_max(matrix, record, x+1, y);
					k1 = sqrt(k1);
					k2 = sqrt(k2);
					int k = min(k1, k2);
					if(k == 0)
						record[x][y] = 1;
					else
					{
						if(matrix[x+k][y+k] == '1')
							record[x][y] = (k+1)*(k+1);
						else
							record[x][y] = k*k;
					}		
				}
				else
				{
					record[x][y] = 1;
				}	
			}
			return record[x][y];	
		}	
			
	}
};

/*
  动态规划。
  设f(i, j)为以(i, j)为左上角顶点的最大正方形面积
  若m(i,j)=0, f(i,j)=0.
  否则
    设x = min(sqrt(f(i，j+1)), sqrt(f(i+1,j)))
    若x=0, f(i,j)=1.
    否则
      若m(i+x,j+x)=0, f(i,j) = x*x.
      否则, f(i,j) = (x+1)*(x+1).
      
*/
