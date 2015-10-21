/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution 
{

	public:

	int maxProduct(vector<int>& nums) 
	{

		int n1_max, n2_max, n2_min;
		for(int i = nums.size()-1; i >= 0; i--)
		{
			if(i == nums.size()-1)
			{
				n1_max = nums[i];
				n2_max = nums[i];
				n2_min = nums[i];
			}
			else
			{
				int new_n1_max = max(n1_max, n2_max);
				int new_n2_max;
				int new_n2_min;
				if(nums[i] >= 0)
				{
					new_n2_max = max(n2_max*nums[i], nums[i]);
					new_n2_min = min(n2_min*nums[i], nums[i]);
				}
				else
				{
					new_n2_max = max(n2_min*nums[i], nums[i]);
					new_n2_min = min(n2_max*nums[i], nums[i]);
				}
				
				n1_max = new_n1_max;
				n2_max = new_n2_max;
				n2_min = new_n2_min;
			}	
		}
		return max(n1_max, max(n2_max, n2_min));	
	}

};

/*
  动态规划
  设f_max(i, j)为不包含i的i至j最大乘子串的乘积.
  设h_max(i, j)为包含i的i至j最大乘子串的乘积.
  设h_min(i, j)为包含i的i至j最小乘子串的乘积.
  f_max(i, j) = max(f_max(i+1, j), h_max(i+1, j))
  若nums[i] >= 0
    h_max(i, j) = max(h_max(i+1, j)*nums[i], nums[i]).
    h_min(i, j) = min(h_min(i+1, j)*nums[i], nums[i]).
  否则
    h_max(i, j) = max(h_min(i+1, j)*nums[i], nums[i]).
    h_min(i, j) = min(h_max(i+1, j)*nums[i], nums[i]).
*/
