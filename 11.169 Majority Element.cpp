/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

class Solution 
{
	public:

	int majorityElement(vector<int>& nums) 
	{
		if(nums.size() == 1)
			return nums[0];
		sort(nums.begin(), nums.end());
		int time = floor(nums.size()/2)+1;

		for(int i = 0; i < nums.size(); i++)
		{
			int t = 1;
			int k;
			while(k < nums.size() && nums[i] == nums[k])
			{
				t++;
				if(t == time)
					return nums[i];
			}
			i = k-1;	
		}	
			
        }

};

int main()
{
	Solution s;
	int n;
	vector<int> num;
	while(scanf("%d", &n) == 1)
	{
		num.push_back(n);	
	}
	printf("%d\n", s.majorityElement(num));
	return 0;	
}

/*
  排序后一遍扫描，为O(nlogn).
*/
