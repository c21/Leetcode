/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution 
{

	public:

    	int findMin(vector<int>& nums) 
	{
/*
		int min = nums[0];
		for(int i = 1; i < nums.size(); i++)
		{
			if(min > nums[i])
				min = nums[i];
		}	
		return min;
*/
						
       		return findMin(nums, 0, nums.size()-1); 

    	}

	int get_min(vector<int>& nums, int begin, int end)
	{
		if(nums[begin] <= nums[end])
			return nums[begin];
		else
		{
			int mid = (begin+end)/2;
			if(nums[mid] > nums[end])
				return get_min(nums, mid+1, end);
			else
				return get_min(nums, begin, mid);	
		}
	}
};

/*
  log(n)的方法是观察首尾和中间的元素。
  如果a[0] <= a[n]，那么a[0]-a[n]为排好序，最小元素为a[0].
  如果a[0] > a[n]，则观察a[n/2], 
    如果a[n/2] <= a[n]，那么a[n/2]-a[n]排好序，最小元素在a[0]-a[n/2].
    如果a[n/2] > a[n], 那么最小元素在a[n/2+1]-a[n]中。
  如果想要想log(n)方法，需要观察首尾和中间的元素的大小关系，试着确定答案在其中的一半。
  
*/
