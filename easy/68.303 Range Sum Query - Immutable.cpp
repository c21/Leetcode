/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

class NumArray 
{
    vector<int> sum;
    public:
    NumArray(vector<int> &nums) 
    {
    	int now_sum = 0;
    	for(int i = 0; i < nums.size(); i++)
    	{
    		if(i == 0)
    			now_sum = nums[0];
    		else
    			now_sum += nums[i];
    		sum.push_back(now_sum);
    	}
    }
    
    int sumRange(int i, int j) 
    {
    	if(i == 0)
    		return sum[j];
    	else	
    		return sum[j]-sum[i-1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);


/*
  事先计算f(i): sum(nums[0], ... , nums[i])即可。
*/
