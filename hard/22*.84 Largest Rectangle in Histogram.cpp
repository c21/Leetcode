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


/*
	O(n)方法是记录每个方块的左右两边第一个比它矮的方块。
	遍历每个方块，如果该方块大于栈顶方块高度，入栈。
	否则，找到栈顶方块的右边界，栈顶方块的左边界即为栈顶方块的下一个方块。
*/


class Solution 
{
	public:
	int largestRectangleArea(vector<int>& height) 
	{
		height.push_back(0);
		stack<int> s;
		int max_area = 0;
		int i = 0;
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





