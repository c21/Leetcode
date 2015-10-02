/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/

class Solution 
{

	public:

    	void rotate(vector<int>& nums, int k) 
	{
		if(nums.size() != 0)
		{
			k = k % nums.size();
			if(k != 0)
			{
				reverse(nums, 0, nums.size()-k-1);
				reverse(nums, nums.size()-k, nums.size()-1);
				reverse(nums, 0, nums.size()-1);
			}
		}
			
	}

	// reverse the vector from index i to j
	void reverse(vector<int>& nums, int i, int j)
	{
		for(int k = i; k <= (i+j)/2; k++)
		{
			int tmp = nums[k];
			nums[k] = nums[j-(k-i)];
			nums[j-(k-i)] = tmp;
		}	
	}

};

/*
  n位数组向右移k位(0 < k < n), 相当于将1至(n-k)，(n-k+1)至n互换，可以通过三次反转完成。
*/
