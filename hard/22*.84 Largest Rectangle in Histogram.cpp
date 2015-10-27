/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

class Solution 
{

	public:

	int largestRectangleArea(vector<int>& height) 
	{
		int max = 0;
		for(int i = 0; i < height.size(); i++)
		{
			if(i+1 < height.size() && height[i] <= height[i+1])
				continue;
			int this_a = 0;
			int now_min = height[i];
			for(int j = i; j >= 0; j--)
			{
				if(height[j] < now_min)
					now_min = height[j];
				this_a = now_min * (i-j+1);
				if(max < this_a)
					max = this_a;
			}			
		}
		return max;	
	}

};

/*
  注意到最右端的方块高度必须比它右边未加入的方块高度高。
  所以遍历所有这样的方块，让它作为右端来检查。复杂度为O(n^2).
  O(n)做法用栈，以后再做。
*/
