/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/


class Solution 
{
    public:
    int lengthOfLIS(vector<int>& nums) 
    {
    	int max_len = 0;
    	vector<int> record(nums.size(), 1);
    	for(int i = nums.size()-1; i >= 0; i--)
    	{
    		if(i == nums.size()-1)
    			record[i] = 1;
    		else
    		{
    			for(int j = i+1; j <= nums.size()-1; j++)
    			{
    				if(nums[j] > nums[i])
    					record[i] = max(record[i],1+record[j]);
    			}
    		}
    		max_len = max(max_len, record[i]);
    	}
    	return max_len;
    }
};


/*
  这里是O(n^2)的动态规划方法，O(nlogn)方法以后再做。
*/  
