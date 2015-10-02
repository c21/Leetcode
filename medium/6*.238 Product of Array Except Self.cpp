/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/



class Solution 
{

	public:

    	vector<int> productExceptSelf(vector<int>& nums) 	
	{
		vector<int> result = vector<int>();

		int pro1 = 1;
		for(int i = 0; i < nums.size(); i++)
		{
			if(i != 0)
				pro1 *= nums[i-1];
			result.push_back(pro1);	
		}	

		int pro2 = 1;
		for(int i = nums.size()-1; i >= 0; i--)
		{
			if(i != nums.size()-1)
				pro2 *= nums[i+1];
			result[i] *= pro2;
		}
		return result;
    	}

};

/*
  这题没有想出来，后来看答案是这样：
  把每个output[i]看作：x0*x1*...*x(i-1) * x(i+1)*x(i+2)*...*x(n)
  可以先从前往后一遍扫描累计算出x0*x1*...*x(i-1)
  再从后往前一遍扫描累计算出x(i+1)*x(i+2)*...*x(n)
  以后如果没有思路，试着将xi进行分解，并且写出x(i-1),x(i+1)看前后关系
*/
