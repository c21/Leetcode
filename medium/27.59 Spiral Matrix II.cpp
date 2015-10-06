/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution 
{

	public:

    	vector<vector<int> > generateMatrix(int n) 
	{
		vector<vector<int> > result = vector<vector<int> >();
		if(n == 0)
			return result;

		for(int i = 0; i < n; i++)
		{
			result.push_back(vector<int>());
			for(int j = 0; j < n; j++)
				result[i].push_back(0);
		}

		int dic_x[4] = {0, 1, 0, -1};
		int dic_y[4] = {1, 0, -1, 0};
		int now_d = 0;
		int end = pow(n,2);
		int bx = 0;
		int by = 0;
		for(int i = 1; i <= end; i++)
		{
			result[bx][by] = i;
			if(bx+dic_x[now_d] >= 0 && bx+dic_x[now_d] < n && 
			by+dic_y[now_d] >= 0 && by+dic_y[now_d] < n && result[bx+dic_x[now_d]][by+dic_y[now_d]] == 0)
			{
				bx = bx+dic_x[now_d];
				by = by+dic_y[now_d];
			}			
			else
			{
				now_d = (now_d+1) % 4;
				bx = bx+dic_x[now_d];
                                by = by+dic_y[now_d];
			}	
		}	
		return result;
        

    	}

};

/*
  模拟
*/
