/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/


class Solution 
{

	public:
	int jump(vector<int>& nums) 
	{
		if(nums.size() == 0 || nums.size() == 1)
			return 0;
		int now_max = 0;
		int i = 0;
		int count = 0;
		
		while(i <= nums.size()-1)
		{
			int this_max = 0;
			while(i <= now_max)
			{
				this_max = max(this_max, i+nums[i]);	
				i++;
			}
			now_max = this_max;
			count++;
			if(now_max >= nums.size()-1)
				return count;
		}	
				
	}	
};

/*
  这题没有想出来，用动态规划超时。
  可以用贪心做，不断更新当前可以到达最远的点。
*/
