/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution 
{

	public:

		
	vector<vector<int> > subsets(vector<int>& nums) 
	{
		sort(nums.begin(), nums.end());
		vector<vector<int> > result = vector<vector<int> >();
		vector<int> flag = vector<int>();
		for(int i = 0; i < nums.size(); i++)
			flag.push_back(0);
		
		gen_set(nums, flag, 0, result);			
	
		return result;
	} 

	void gen_set(vector<int>& nums, vector<int>& flag, int begin, vector<vector<int> >& result)
	{
		if(begin == nums.size())
		{
			vector<int> r = vector<int>();
			for(int i = 0; i < flag.size(); i++)
			{
				if(flag[i] == 1)
					r.push_back(nums[i]);
			}	
			result.push_back(r);
		}
		else if(begin < nums.size())
		{
			flag[begin] = 0;
			gen_set(nums, flag, begin+1, result);
			flag[begin] = 1;
			gen_set(nums, flag, begin+1, result);	
		} 
	}
};

int main()
{
	Solution s;
	while(1)
	{
		vector<int> n = vector<int>();
		int x;
		while(scanf("%d", &x) == 1)
		{
			n.push_back(x);
		}
		vector<vector<int> > r = s.subsets(n);
		for(int i = 0; i < r.size(); i++)
		{
			for(int j = 0; j < r[i].size(); j++)
				printf("%d ", r[i][j]);
			printf("\n");
		}
	}
	return 0;
} 

/*
  将原数组排序后枚举所有情况。
*/
