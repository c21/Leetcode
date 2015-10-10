/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

class Solution 
{

	public:

	int threeSumClosest(vector<int>& nums, int target) 
	{
		if(nums.size() < 3)
			return 0;
		sort(nums.begin(), nums.end());
		
		int sum;
		int first_time = 1;	
		for(int i = 0; i <= nums.size()-3; i++)
		{
			int j;
			for(j = i+1; j <= nums.size()-2; j++)
			{
				int k = find(nums, j+1, nums.size()-1, target-nums[i]-nums[j]);	
				int this_sum = nums[i]+nums[j]+k;
				if(first_time)
				{
					sum = this_sum;
					first_time = 0; 
				}
				else
				{
					if(abs(sum-target) > abs(this_sum-target))
						sum = this_sum;
				}
			}	
		}		
		return sum;	
	}

	// find the nearest element for target
	int find(vector<int>& nums, int begin, int end, int target)
	{
		int last;
		while(begin <= end)
		{
			int mid = (begin+end)/2;
			if(nums[mid] == target)
				return target;
			else if(nums[mid] > target)
			{
				end = mid-1;
				last = nums[mid];
			}
			else
			{
				begin = mid+1;
				last = nums[mid];
			}	
		}	
		return last;
	}

};

int main()
{
	Solution s;
	int k;
	while(scanf("%d", &k) == 1)
	{
		vector<int> v = vector<int>();
		int n;
		while(scanf("%d", &n) == 1)
			v.push_back(n);
		printf("%d\n", s.threeSumClosest(v, k));	
	}
	return 0;	
}

/*
  排序以后，遍历前两个点，对于第三个点进行折半搜索确定，复杂度为O((n^2)logn).
*/
