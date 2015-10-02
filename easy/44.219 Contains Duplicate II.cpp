/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

class Solution 
{

	public:

    	bool containsNearbyDuplicate(vector<int>& nums, int k) 
	{
		// my_map[i] is the integer i's last index in array
		map<int,int> my_map = map<int,int>();
		
		for(int i = 0; i < nums.size(); i++)
		{
			if(my_map.find(nums[i]) == my_map.end())
				my_map[nums[i]] = i;
			else
			{
				if(i - my_map[nums[i]] <= k)
					return true;
				else
					my_map[nums[i]] = i;
			}	
		}	
		return false;
	}
};

/*
  记录每个数字出现的最后位置，遇到该数字和它原先的位置进行比较，如果不大于k, 则返回true.
*/
