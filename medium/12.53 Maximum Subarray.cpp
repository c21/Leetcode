/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

class Solution 
{

	public:

    	int maxSubArray(vector<int>& nums) 
	{
		vector<pair<int,int> > result = vector<pair<int,int> >();
		if(nums.size() == 0)
			return 0;
		else
		{
			for(int i = 0; i < nums.size(); i++)
			{	
				if(i == 0)
				{
					result.push_back(pair<int,int>(nums[i],nums[i]));
				}	
				else
				{
					int f1 = max(result[i-1].first, result[i-1].second);
					int f2 = max(nums[i], nums[i]+result[i-1].second);
					result.push_back(pair<int,int>(f1, f2));
				}
			}
			return max(result[nums.size()-1].first, result[nums.size()-1].second);
		}			
    	} 

};

int main()
{
	Solution s;
	int n;
	vector<int> nums = vector<int>();
	while(scanf("%d", &n) == 1)
	{
		nums.push_back(n);
	}
	printf("%d\n", s.maxSubArray(nums));
	return 0;
}

/*
  动态规划
  f(i,0)代表1-i不包括i的最大连续和，f(i-1)代表1-i包括i的最大连续和。
  f(i,0) = max(f(i-1,0),f(i-1,1))
  f(i,1) = max(nums[i], f(i-1,1)+nums[i])
*/
