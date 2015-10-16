/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
*/

#include <vector>
#include <utility>
#include <cstdio>

using namespace std;

class Solution 
{

	public:

	vector<int> majorityElement(vector<int>& nums) 
	{		
		pair<int,int> n1 = pair<int,int>(0, -1);
		pair<int,int> n2 = pair<int,int>(0, -1);
		vector<int> result = vector<int>();
		if(nums.size() == 0)
			return result;
		for(int i = 0; i < nums.size(); i++)
		{
			if(n1.second >= 0 && nums[i] == n1.first)
				n1.second++;
			else if(n2.second >= 0 && nums[i] == n2.first)
				n2.second++;	
			else if(n1.second <= 0)
			{
				n1.first = nums[i];
				n1.second = 1;
			}
			else if(n2.second <= 0)
			{
				n2.first = nums[i];
				n2.second = 1;
			}
			else
			{
				n1.second--;
				n2.second--;
			}
	//		printf("[i]: %d n1:(%d ,%d) n2:(%d, %d)\n", nums[i], n1.first, n1.second, n2.first, n2.second);
		}
	//	printf("final: n1:(%d ,%d) n2:(%d, %d)\n", n1.first, n1.second, n2.first, n2.second);		
		int c1 = 0;
		int c2 = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			if(n1.second >= 0 && nums[i] == n1.first)
				c1++;
			else if(n2.second >= 0 && nums[i] == n2.first)
				c2++;	
		}
		if(n1.second >= 0 && c1 > nums.size()/3)
			result.push_back(n1.first);
		if(n2.second >= 0 && c2 > nums.size()/3)
                        result.push_back(n2.first);
		return result;
	}

};

int main()
{
	Solution s;
	vector<int> n = vector<int>();
	int k;
	while(scanf("%d", &k) == 1)
	{
		n.push_back(k);
	}		
	vector<int> r = s.majorityElement(n);
	for(int i = 0; i < r.size(); i++)
		printf("%d ", r[i]);
	printf("\n");
	return 0;	
}

/*
  这题没有做出来。
  答案用的方法是记录两个候补众数
  如果当前数等于其中一个候补众数，个数加一
  否则，如果候补众数有空，当前数填入，个数设为一
  否则，当前两个候补众数个数都减一
  再遍历一次数组，确定候补众数的个数。
*/
