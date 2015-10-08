/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

#include <cstring>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;


class Solution 
{

	public:

	int numSquares(int n) 
	{
		int* array = (int*)malloc(sizeof(int)*(n+2));
		//memset(array, 0, sizeof(array));
    for(int i = 1; i <= n; i++)
      array[i] = 0;
		vector<int> table = vector<int>();

		for(int i = 1; i*i <= n; i++)
		{
			table.push_back(i*i);
			array[i*i] = 1;
		}	

		for(int i = 1; i < n; i++)
		{
			if(array[i] > 0)
			{
				for(int j = 0; table[j]+i <= n && j < table.size(); j++)
				{
					if(array[table[j]+i] == 0)
						array[table[j]+i] = array[i]+1;
					else
						array[table[j]+i] = min(array[table[j]+i], array[i]+1);
				}
			}
		}	
		return array[n];
	}

};

int main()
{
	Solution s;
	int n;
	while(scanf("%d", &n) == 1)
	{
		printf("%d\n", s.numSquares(n));
	}
	return 0;
}

/*
  动态规划。
  perfect square number，完全平方数，是可以分解为i*i的数。
  设f(n)为n分解的最小数目
  f(n) = min{f(n-i)+i | i为不大于n的完全平方数}
  另外可以用数论知识做，以后再做。
*/
