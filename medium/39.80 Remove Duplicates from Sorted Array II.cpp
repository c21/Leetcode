/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
class Solution 
{

	public:

  int removeDuplicates(vector<int>& nums) 
	{
		if(nums.size() == 0)
			return 0;
		else
		{
      sort(nums.begin(), nums.end());
		
			int p1 = 0;
			int p2 = 0;
			while(p2 < nums.size())
			{
				nums[p1] = nums[p2];
				p1++;
				int k = nums[p2];
				if(p2+1 < nums.size() && nums[p2+1] == nums[p2])
				{
					nums[p1] = nums[p2+1];
					p1++;
					p2++;
				}
				while(p2 < nums.size() && nums[p2] == k)
					p2++;
			}
		
			return p1;
		}			
  }

};

int main()
{
	Solution s;
	vector<int> r = vector<int>();
	int n;
	while(scanf("%d", &n) == 1)
	{
		r.push_back(n);
	}
	int k = s.removeDuplicates(r);
	printf("%d\n", k);
	for(int i = 0; i < k; i++)
		printf("%d ", r[i]);
	printf("\n");
	return 0;
}

/*
  排序后遍历一遍删除。
*/
