/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

class Solution 
{

	public:

    	vector<int> singleNumber(vector<int>& nums) 
	{
		unordered_map<int,int> my_map = unordered_map<int,int>();

		for(int i = 0; i < nums.size(); i++)
		{
			if(my_map.count(nums[i]) == 0)
				my_map[nums[i]] = 1;
			else
				my_map.erase(nums[i]);
		}	
		vector<int> r = vector<int>();	
        	for(unordered_map<int,int>::iterator p = my_map.begin(); p != my_map.end(); p++)
			r.push_back(p->first);
		return r;

    	}

};

/*
  这里使用unordered_map方法，如果要O(1)空间复杂度，需要用异或。
*/
