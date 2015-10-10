/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

#include <vector>
#include <cstdio>

using namespace std;

class Solution 
{

	public:

	bool canJump(vector<int>& nums) 
	{
		if(nums.size() == 0)
			return false;
		else if(nums.size() == 1)
			return true;
		else
		{
			int last_able;
			for(int i = nums.size()-1; i >= 0; i--)
			{
				if(i == nums.size()-1)
				{
					last_able = i;
				}
				else
				{
					if(i+nums[i] >= last_able)
					{
						last_able = i;
					}
				}	
			}
			return last_able == 0;
		}
	}
};

int main()
{
	Solution s;
	while(1)
	{
		vector<int> r = vector<int>();
		int k;
		while(scanf("%d", &k) == 1)
			r.push_back(k);
		printf("%d\n", s.canJump(r));
	}
	return 0;
}

/*
  很巧妙的一道题。
  一开始想用动态规划，超时。
  后来发现可以从后往前扫描时只记录最后一个可以到达终点的点，如果当前点可到达该点，当前点也可到达终点。
  复杂度为O(n).
*/
