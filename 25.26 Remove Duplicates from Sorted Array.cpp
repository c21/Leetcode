/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

class Solution 
{
	public:

	int removeDuplicates(vector<int>& nums) 
	{
		// to record the place of new vector and old vector
		int p_old = 0;
		int p_new = 0;
		
		for(; p_old < nums.size(); p_old++)
		{
			if(p_old != p_new)
				nums[p_new] = nums[p_old];
			p_new++;

			int k = p_old+1;
			while(k < nums.size() && nums[k] == nums[p_old])
				k++;
			p_old = k-1;		
		}	

		return p_new;	
	}

};

/*
  模拟。由于不需要管被删除的元素，可以记录新数组和旧数组的当前最后元素位置，遇到新元素直接赋值就可以了。
*/
