/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution 
{

	public:

    	int singleNumber(vector<int>& nums) 
	{
		unordered_map<int,int> my_map = unordered_map<int,int>();

		for(int i = 0; i < nums.size(); i++)
		{
			if(my_map.find(nums[i]) == my_map.end())
				my_map[nums[i]] = 1;
			else
				my_map[nums[i]]++;
		}	
		for(unordered_map<int,int>::iterator p = my_map.begin(); p != my_map.end(); p++)
		{
			if(p->second != 3)
				return p->first;
		}
        

    	}

};

/*
  使用hashing空间复杂度为O(n), O(1)空间复杂度需要将每个数的每个数位取模。
*/
