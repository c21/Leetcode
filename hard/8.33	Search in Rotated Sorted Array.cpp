/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution 
{

	public:

    	int search(vector<int>& nums, int target) 
	{
		if(nums.size() == 0)
			return -1;
		else
			return get_idx(nums, 0, nums.size()-1, target);	
        

    	}

	int get_idx(vector<int>& array, int begin, int end, int t)
	{
		if(begin == end)
		{
			if(array[begin] == t)
				return begin;
			else
				return -1;
		}
		else if(begin < end)
		{
			int mid = (begin+end)/2;
			if(array[mid] >= array[begin] && array[mid] <= array[end])
			{
				if(array[mid] == t)
					return mid;
				else if(array[mid] < t)
					return get_idx(array, mid+1, end, t);
				else
					return get_idx(array, begin, mid-1, t);	
			}
			else if(array[mid] >= array[begin] && array[mid] > array[end])
			{
				if(array[mid] == t)
					return mid;
				else if(array[mid] < t)
                                        return get_idx(array, mid+1, end, t);	
				else
				{
					if(array[end] >= t)
						return get_idx(array, mid+1, end, t);
					else
						return get_idx(array, begin, mid-1, t);
					
				}
			}
			else if(array[mid] < array[begin] && array[mid] <= array[end])
			{
				if(array[mid] == t)
                                        return mid;
                                else if(array[mid] > t)
                                        return get_idx(array, begin, mid-1, t);
				else
				{
					if(array[end] >= t)
						return get_idx(array, mid+1, end, t);
					else
						return get_idx(array, begin, mid-1, t);
				}
			}
		}
		else
			return -1;	
	}
};
