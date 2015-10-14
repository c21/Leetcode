/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution 
{

	public:

	void nextPermutation(vector<int>& nums) 
	{
		if(nums.size() >= 2)
		{
			int i;
			for(i = nums.size()-1; i >= 1; i--)
			{
				if(nums[i] > nums[i-1])
				{
					int begin = nums[i-1];
					int j;
					for(j = nums.size()-1; j >= i; j--)
					{
						if(nums[j] > nums[i-1])
							break;
					}		
					nums[i-1] = nums[j];
					nums[j] = begin;
					begin = i;
					int end = nums.size()-1;
					for(int j = 0; j <= (begin+end)/2-begin; j++)
					{
						int tmp = nums[begin+j];
						nums[begin+j] = nums[end-j];
                                        	nums[end-j] = tmp;
					}
					break;	
				}
			}	
			if(i == 0)
			{
				for(int i = 0; i <= (nums.size()-1)/2; i++)
				{
					int tmp = nums[i];
					nums[i] = nums[nums.size()-1-i];
					nums[nums.size()-1-i] = tmp;	
				}	
			}
		}	
	}

};

int main()
{
	Solution s;
	vector<int> r = vector<int>();
	int k;
	while(scanf("%d", &k) == 1)
	{
		r.push_back(k);
	}		
	s.nextPermutation(r);
	for(int i = 0; i < r.size(); i++)
		printf("%d ", r[i]);
	printf("\n");
	return 0;
}

/*
  这道题没有想对。
  方法是：从后往前找到第一个nums[i], nums[i-1] < nums[i].
  然后从后至nums[i]找到第一个nums[j], nums[i-1] < nums[j].
  交换nums[i-1]和nums[j].
  翻转nums[i]~nums[n].
*/
