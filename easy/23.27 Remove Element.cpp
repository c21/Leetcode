/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

#include <cstdio>
#include <vector>
using namespace std;


class Solution 
{
	public:

    	int removeElement(vector<int>& nums, int val) 
	{
		// put all instances of that value at the end of array
		int count = 0;
		for(int i = 0; i < nums.size()-count; i++)
		{
			if(nums[i] == val)
			{
				count++;
				nums[i] = nums[nums.size()-count];
				nums[nums.size()-count] = val;
				i--;	
			}	
		}
		return nums.size()-count;		
    	}

};


int main()
{
	Solution s;
	vector<int> array = vector<int>();
	int n;
	while(scanf("%d", &n) == 1)
	{
		array.push_back(n);	
	}	
	int len = s.removeElement(array, 2);
	printf("%d\n", len);

	for(int i = 0; i < array.size(); i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;	
}

/*
  模拟
*/
