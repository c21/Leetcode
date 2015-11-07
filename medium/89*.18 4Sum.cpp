/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution 
{

	public:

	int global;
	vector<vector<int> > fourSum(vector<int>& nums, int target) 
	{
		vector<vector<int> > result = vector<vector<int> >();
		if(nums.size() == 0)
			return result;
	
		sort(nums.begin(), nums.end());	
		vector<int> flag = vector<int>();
		global = nums[0];
		for(int i = 0; i < nums.size(); i++)
		{
			nums[i] = nums[i]-global;
			flag.push_back(0);	
		}	
		find(result, nums, flag, 0, 0, target-global*4);	
		return result;	
	}

	void find(vector<vector<int> >& result, vector<int>& nums, vector<int>& flag, int begin, int k, int t)
	{
		if(begin >= flag.size())
			return;
		if(k == 3)
		{
			int b = begin;
			int e = nums.size()-1;
			int find_flag = 0;
			while(b <= e)
			{
				int mid = (b+e)/2;
				if(nums[mid] == t)
				{
					find_flag = 1;
					break;	
				}
				else if(nums[mid] < t)
				{
					b = mid+1;
				}
				else
				{
					e = mid-1;
				}
			}	
			if(find_flag)
			{
				vector<int> r = vector<int>();
				for(int i = 0; i < flag.size(); i++)
				{
					if(flag[i])
						r.push_back(nums[i]+global);
				}
				r.push_back(t+global);
				result.push_back(r);
			}	
		}
		else
		{
			for(int i = begin; i < flag.size(); i++)
			{
				if(nums[i] > t)
					break;
				flag[i] = 1;
				find(result, nums, flag, i+1, k+1, t-nums[i]);
				flag[i] = 0;
				int j = i+1;
				while(j < flag.size() && nums[i] == nums[j])
					j++;
				i = j-1;			
			}	
		}
	}	
};

int main()
{
	Solution s;
	int k;
	while(scanf("%d", &k) == 1)
	{
		vector<int> n = vector<int>();
		int x;
		while(scanf("%d", &x) == 1)
			n.push_back(x);
		vector<vector<int> > r = s.fourSum(n, k);
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
  枚举前3个数，然后对于第4个数进行二分查找。
  有通用的方法解决kSum, 以后再做。
*/


/*
	将数组排序，然后枚举前两个数，对于后两个数用一次扫描(2Sum).
	或者，可以枚举第一个数，对于后三个数求和(3Sum). 实现相同，时间复杂度为O(n^3).
*/
class Solution 
{
public:
vector<vector<int> > fourSum(vector<int>& nums, int target) 
{
	vector<vector<int> > r;
	if(nums.size() < 4)
		return r;
	sort(nums.begin(), nums.end());

for(int i = 0; i <= nums.size()-4; i++)
{
	if(i != 0 && nums[i] == nums[i-1])
		continue;
	for(int j = i+1; j <= nums.size()-3; j++)
	{
		if(j != i+1 && nums[j] == nums[j-1])
			continue;
		vector<pair<int,int> > this_r;
		get_sum(nums, j+1, target-nums[i]-nums[j], this_r);
		for(int k = 0; k < this_r.size(); k++)
		{
			vector<int> sum;
			sum.push_back(nums[i]);
			sum.push_back(nums[j]);
			sum.push_back(this_r[k].first);
			sum.push_back(this_r[k].second);
			r.push_back(sum);
		}
	}
}	
return r;
      }
	
	void get_sum(vector<int>& nums, int b, int sum, vector<pair<int,int> >& r)
	{
		int begin = b;
		int end = nums.size()-1;
		while(begin < end)
		{
			int f1 = 0, f2 = 0;
			if(nums[begin]+nums[end] == sum)
			{
				r.push_back(make_pair(nums[begin], nums[end]));
				f1 = 1;
				f2 = 1;
			}
			else if(nums[begin]+nums[end] < sum)
			{
				f1 = 1;
			}
			else
			{
				f2 = 1;
			}
			if(f1)
			{
				int j = begin+1;
				while(j < end && nums[j] == nums[begin])
					j++;
				begin = j;
			}
			if(f2)
			{
				int j = end-1;
				while(j > begin && nums[j] == nums[end])
					j--;
				end = j;
			}
		}
	}
	
};


