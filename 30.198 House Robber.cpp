/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

#include <vector>
#include <cstdio>

using namespace std;

class Solution
{

	public:

    	int rob(vector<int>& nums) 
	{
		// f[i] is the maximum amount of money to rob from 1-i houses 
		vector<int> f = vector<int>();	

		if(nums.size() == 0)
			return 0;
		else if(nums.size() == 1)
			return nums[0];

		// f[0] = 0, f[1] = nums[0].
		f.push_back(0);
		f.push_back(nums[0]);

		for(int i = 2; i <= nums.size(); i++)
		{
			f.push_back(max(f[i-1], nums[i-1]+f[i-2]));	
		}		

		return f[nums.size()];
    	}

};


int main()
{
	vector<int> r = vector<int>();

	int n;
	while(scanf("%d", &n) == 1)
		r.push_back(n);

	Solution s;
	printf("%d\n", s.rob(r));	
	return 0;			
}

/*
  动态规划。
  设f(i)为抢第1-i家所获最多钱，m(i)为第i家钱。
  则有：f(i) = max(f(i-1), m(i)+f(i-2))
*/
