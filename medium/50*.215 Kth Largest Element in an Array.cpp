/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Solution 
{

	public:

	int findKthLargest(vector<int>& nums, int k) 
	{
		return find_num(nums, k);	
	}

	int find_num(vector<int>& nums, int k)
	{
//		int p = rand()%nums.size();
		int p = 0;
		vector<int> less = vector<int>();
		vector<int> more = vector<int>();
		vector<int> same = vector<int>();
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] < nums[p])
				less.push_back(nums[i]);
			else if(nums[i] > nums[p])
				more.push_back(nums[i]);
			else
				same.push_back(nums[i]);
		}
		if(more.size() <= k-1)
		{
			if(more.size()+same.size() >= k)
				return nums[p];
			else
				return find_num(less, k-same.size()-more.size());
		}
		else
				return find_num(more, k);
	}	

};

int main()
{
	Solution s;
	int k, n;
	while(scanf("%d", &k) == 1)
	{
		vector<int> r = vector<int>();
		while(scanf("%d", &n) == 1)
		{
			r.push_back(n);
		}
		printf("%d\n", s.findKthLargest(r, k));
	}
	return 0;
}

/*
  可以使用快排的方案，每次随机选一个元素，对整个数组做划分，然后可以再递归搜索其中的一份。
*/
