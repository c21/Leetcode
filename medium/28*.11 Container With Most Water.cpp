/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

class Solution 
{

	public:

    	int maxArea(vector<int>& height) 
	{
    		int result = 0;
		int begin = 0;
		int end = height.size()-1;
		while(begin < end)
		{
			int now_r = (end-begin)*min(height[end],height[begin]);
			if(now_r > result)
				result = now_r;

			if(height[begin] < height[end])
			{
			//	int this = height[begin];
				begin++;
			//	while(begin < end && height[begin] <= this)
			//		begin++;
			}	
			else
			{
			//	int this = height[end];
				end--;
			//	while(begin < end && this >= height[end])
			//		end--;
			}
		}		
		return result;
	}

};

/*
  这题没有做出来，看了答案发现是最开始确定两边为最左端和最右端，
  如果左端较小，应该再观察左端的右边一个，不需要再观察左端，因为高度由左端决定，其他的情况必定没有现在的大。
  如果右端较小，应该再观察右端的左边一个。
  复杂度为O(N).
*/
