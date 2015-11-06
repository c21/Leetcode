/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/

class Solution 
{

	public:

	int maximalRectangle(vector<vector<char> >& matrix) 
	{
		if(matrix.size() == 0 || matrix[0].size() == 0)
			return false;
		int row = matrix.size();
		int col = matrix[0].size();

		vector<int> height = vector<int>();
		int max_area = 0;
		for(int i = 0; i < row; i++)
		{
			if(i == 0)
			{
				for(int j = 0; j < col; j++)
				{
					if(matrix[i][j] == '0')
						height.push_back(0);
					else
						height.push_back(1);
				}
			}	
			else
			{
				for(int j = 0; j < col; j++)
        {
          if(matrix[i][j] == '0')
            height[j] = 0;
          else
            height[j]++;
        }
			}

			int this_a = get_area(height);
			max_area = max(max_area, this_a);	
		}

		return max_area;					
	}

	int get_area(vector<int>& height)
	{
		int max_area = 0;
		for(int i = 0; i < height.size(); i++)
		{
			if(i+1 < height.size() && height[i] <= height[i+1])
				continue;
			int min_num = height[i];
			int j = i;
			while(j >= 0)
			{
				if(height[j] < min_num)
					min_num = height[j];
				int this_a = min_num * (i-j+1);
				max_area = max(max_area, this_a);
				j--;
			}		
		}		
		return max_area;
	}	
};

/*
  这道题没想出来，用动态规划求正方形的方法好像没法做。
  看了答案发现，依次对每一行作为矩形的最下边，统计每列以最下边为底边的连续1的个数。
  仿照求直方图最大面积的方法，求出的面积即为以该行为最下边的矩形的最大面积。
  依次枚举所有行，得到最大矩形。
  这里求直方图用的是O(n^2)的方法，总时间复杂度为O(n^3). 求直方图有O(n)方法，以后再做。
*/


/*
	以每一行为底边，便可以看作求底边往上的直方图面积，直方图面积求法为O(n)，总时间复杂度为O(n^2).
*/

class Solution 
{
    public:
    int maximalRectangle(vector<vector<char> >& matrix) 
    {
    	if(matrix.size() == 0 || matrix[0].size() == 0)
    		return 0;
    	vector<int> height(matrix[0].size(), 0);
    	int max_area = 0;
        for(int i = 0; i < matrix.size(); i++)
    	{
    		for(int j = 0; j < matrix[i].size(); j++)
    		{
    			if(matrix[i][j] == '0')
    				height[j] = 0;
    			else
    				height[j]++;
    		}
    		int this_area = get_area(height);
    		max_area = max(max_area, this_area);
    	}
    	return max_area;
     }

	int get_area(vector<int>& height)
	{
		height.push_back(0);
		stack<int> s;
		int i = 0;
		int max_area = 0;
		while(i < height.size())
		{
			if(s.size() == 0 || height[s.top()] <= height[i])
			{
				s.push(i);
				i++;
			}
			else
			{
				int j = s.top();
				s.pop();
				int this_area;
				if(s.size() == 0)
					this_area = height[j]*i;
				else
					this_area = height[j]*(i-s.top()-1);
				max_area = max(max_area, this_area);
			}
		}
		height.pop_back();
		return max_area;
	}
};
