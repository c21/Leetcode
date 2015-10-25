/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

class Solution 
{

	public:

	int findDuplicate(vector<int>& nums) 
	{
		int begin = 1, end = nums.size()-1;
		while(begin < end)
		{
			int mid = (begin+end)/2;
			int count = 0;
			for(int i = 0; i < nums.size(); i++)		
			{
				if(nums[i] <= mid)
					count++;
			}
			if(count <= mid)
				begin = mid + 1;
			else
				end = mid-1; 	
		}	
		return begin;
	}

};

/*
  这题没有想出来。
  答案方法是n+1个数，全部为1-n, 取n/2, 统计小于或等于n/2的数的个数
  如果数目小于或等于n/2, 那么重复数在[n/2+1, n]中， 否则，在[1, n/2-1]中。时间复杂度O(nlogn)
*/
