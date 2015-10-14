/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

#include <vector>
#include <cstdio>

using namespace std;

class Solution 
{

	public:

	int minSubArrayLen(int s, vector<int>& nums) 
	{
		int begin = 0;
		int sum = 0;
		int min_len = 0;
			
		int i = 0;
		while(i < nums.size())
		{
			if(sum + nums[i] >= s)
			{
				sum = sum + nums[i];
				while(sum >= s && begin <= i)
				{
					sum -= nums[begin];
					begin++;
				}
				int this_len = i-begin+2;
                                if(min_len == 0 || min_len > this_len)
                                        min_len = this_len;
				i++;
			}	
			else
			{
				sum = sum + nums[i];
				i++;
			}
		}
		return min_len;
	}

};


int main()
{
	Solution s;
	int x;
	while(scanf("%d", &x) == 1)
	{
		vector<int> r = vector<int>();
		int n;
		while(scanf("%d", &n) == 1)
			r.push_back(n);
		printf("%d\n", s.minSubArrayLen(x, r));	
	}	
	return 0;
}


/*
  从前往后扫描，遇到和大于s的时候进行记录，时间复杂度为O(n).
*/
