/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
*/

class Solution 
{

	public:

	int trap(vector<int>& height) 
	{
		int sum = 0;
		int p = 0;
		while(p < height.size() && height[p] == 0)
			p++;
		while(p < height.size())
		{
			int q = p+1;
			int max = p+1;
			int t_sum = 0;
			while(q < height.size() && height[q] < height[p])
			{
				if(q != max && height[q] > height[max])
					max = q;
				t_sum += height[p] - height[q];
				q++;
			}	
			if(q == height.size())
			{
				for(int i = p+1; i < height.size() && i <= max-1; i++)
					sum += height[max] - height[i];
				p = max;
			}
			else
			{
				sum += t_sum;
				p = q;	
			}	
		}		
		return sum;	
	}

};

/*
  从第一个非0方块开始扫描。
  扫描时记录与该方块的高度差，以及最高的方块。
  如果遇到高度不小于当前方块的方块，停止。
  否则，以最高的方块为停止处。
*/
