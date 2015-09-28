/*

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/


#include <vector>
#include <cstdio>

using namespace std;

class Solution {

	public:

    	void moveZeroes(vector<int>& nums) 
	{
		// move all non-zero elements to the beginning
		for(int i = 1; i < nums.size(); i++)
		{
			if(nums[i] != 0)
			{
				int x = nums[i];
				for(int j = i-1; j >= 0 && nums[j] == 0; j--)
				{
					nums[j] = x;
					nums[j+1] = 0;		
				}
			
			}	
		}	
    	}

};

int main()
{
	Solution s;
	int n;
	vector<int> nums;
	while(scanf("%d", &n) == 1)
	{
		nums.push_back(n);
	}	
	s.moveZeroes(nums);
	for(int i = 0; i < nums.size(); i++)
		printf("%d ", nums[i]);
	printf("\n");
	return 0;
}

/*
  模拟
*/
