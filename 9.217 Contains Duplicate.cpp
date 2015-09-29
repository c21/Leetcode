/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

#include <algorithm>
class Solution 
{

	public:

	bool containsDuplicate(vector<int>& nums) 
	{
		/*
		for(int i = 0; i < nums.size()-1; i++)
		{
			for(int j = i+1; j < nums.size(); j++)
			{
				if(nums[i] == nums[j])
					return false;	
			}
		}
		*/
		if(nums.size() == 0)
			return false;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size()-1; i++)
		{
			if(nums[i] == nums[i+1])
				return true;
		}		
		return false;
        }

};

/*
 这题暴力会超时，排序后再一遍扫描。
*/
