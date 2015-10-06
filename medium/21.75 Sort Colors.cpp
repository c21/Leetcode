/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

class Solution 
{

	public:

    	void sortColors(vector<int>& nums) 
	{
		int count[3];
		memset(count, 0, sizeof(count));
		for(int i = 0; i < nums.size(); i++)
		{
			count[nums[i]]++;
		}
		int k = 0;
		for(int i = 1; i <= count[0]; i++)
		{
			nums[k] = 0;
			k++;
		}
		for(int i = 1; i <= count[1]; i++)
                {
                        nums[k] = 1;
                        k++;
                }
		for(int i = 1; i <= count[2]; i++)
                {
                        nums[k] = 2;
                        k++;
                }
	

    	}
};


int main()
{
	Solution s;
	int n;
	vector<int> v = vector<int>();
	while(scanf("%d", &n) == 1)
	{
		v.push_back(n);
	}	
	s.sortColors(v);
	for(int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}

/*
  模拟
*/
