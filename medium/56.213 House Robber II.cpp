/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution 
{

	public:

	int rob(vector<int>& nums) 
	{
		if(nums.size() == 0)
			return 0;
		else if(nums.size() == 1)
			return nums[0];

		// not rob the first home
		int r1;
		vector<int> result = vector<int>();
		for(int i = 0; i < nums.size(); i++)
			result.push_back(0);

		for(int i = nums.size()-1; i >= 1; i--)
		{
			if(i == nums.size()-1)
				result[i] = nums[i];
			else if(i == nums.size()-2)
				result[i] = max(nums[i], nums[i+1]);
			else
				result[i] = max(result[i+1], result[i+2]+nums[i]);							
		}	
		r1 = result[1];

		for(int i = nums.size()-2; i >= 0; i--)
		{
			if(i == nums.size()-2)
				result[i] = nums[i];
			else if(i == nums.size()-3)
				result[i] = max(nums[i], nums[i+1]);
			else
				result[i] = max(result[i+1], result[i+2]+nums[i]);
		}
		int r2 = result[0];

		return max(r1, r2);
			
	}

};

/*
  动态规划。
  设f(i)为抢i至n家的最大钱数
  设g(i)为抢i至n-1家的最大钱数
  g/f(i) = max(g/f(i+1), nums[i]+g/f(i+2))
  返回max(f(2), g(1)).
*/
