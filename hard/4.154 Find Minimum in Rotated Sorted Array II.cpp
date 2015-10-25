/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

class Solution 
{

	public:

	int findMin(vector<int>& nums) 
	{
		if(nums.size() == 1)
			return nums[0];
		int begin = 0, end = nums.size()-1;
		int min = nums[0];
		while(begin <= end)
		{
			int mid = (begin+end)/2;
			if(nums[mid] < nums[end])
			{
				if(nums[mid] < min)
					min = nums[mid];
				end = mid-1;	
			}		
			else if(nums[mid] > nums[end])
			{
				if(nums[mid] < min)
					min = nums[mid];
				begin = mid+1;		
			}
			else
			{
				if(nums[mid] != nums[begin])
				{
					if(nums[mid] < min)
                                        	min = nums[mid];
                                	end = mid-1;
				}	
				else 
				{
					for(int i = begin; i <= end; i++)
					{
						if(nums[i] < min)
							min = nums[i];
					}
					break;
				}
			}
		}		
		return min;
	}

};

/*
  比较中点和起点和终点的关系。
  设三点为a[b], a[m], a[e].
  如果a[m] < a[e], 那么最小值在a[b-m]中。
  如果a[m] > a[e], 那么最小值在a[m-e]中。
  如果a[m] = a[e],
      如果a[m] < a[b], 那么最小值在a[b-m]中。
      如果a[m] > a[b], 那么最小值在a[b-m]中。
      如果a[m] = a[b], 那么最小值在a[b-e]中。(这种情况扫描一遍数组确定最小值)
*/
