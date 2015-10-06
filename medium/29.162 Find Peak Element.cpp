/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
*/

class Solution 
{

	public:

    	int findPeakElement(vector<int>& nums) 
	{
		if(nums.size() == 0)
			return -1;
		else
			return find_max(nums, 0, nums.size()-1);	
    	}

	int find_max(vector<int>& array, int begin, int end)
	{
		if(begin == end)
			return begin;
		else if(begin+1 == end)
		{
			if(array[begin] < array[end])
				return end;
			else
				return begin;
		}
		else if(begin < end)
		{
			int mid = (begin+end)/2;
			if(array[mid-1] < array[mid])
				return find_max(array, mid, end);
			else
				return find_max(array, begin, mid-1);	
				
		}	
	}
};

/*
  O(logn)的做法是折半搜索，取中间元素nums[mid].
  如果nums[mid] > nums[mid-1], 那么nums[mid...end]必定有peak element
  如果nums[mid] < nums[mid-1], 那么nums[begin...mid-1]必定有peak element
*/
