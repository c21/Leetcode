/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

class Solution 
{

	public:

	int firstMissingPositive(vector<int>& nums) 
	{
		if(nums.size() == 0)
			return 1;

		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != i+1)
			{
				if(nums[i] >= 1 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i])
				{
					int tmp = nums[i];
					int place = nums[i];
					nums[i] = nums[place-1];
					nums[place-1] = tmp;
					i--;
				}
			}
		}

		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != i+1)
				return i+1;
		}	
		return nums.size()+1;
	}

};

/*
  常数空间复杂度有时意味着需要修改数组，扫描一遍，将nums[i]归位于nums[i]-1. 即nums[nums[i]-1] = nums[i].
*/
