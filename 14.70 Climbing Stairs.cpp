/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <cstdio>

class Solution 
{
	public:

	int climbStairs(int n) 
	{
		if(n == 1)
			return 1;
		else if(n == 2)
			return 2;
		else if(n >= 3)
		{
			int pre1 = 1;
			int pre2 = 2;
			int now;
			for(int i = 3; i <= n; i++)
			{
				now = pre1 + pre2;
				pre1 = pre2;
				pre2 = now;
			}		
			return now;
		}

			
        }

};

int main()
{
	Solution s;
	int n;
	scanf("%d", &n);
	printf("%d\n", s.climbStairs(n));
	return 0;
}

/*
  动态规划，设f(n)为爬n阶台阶的爬法，则f(n) = f(n-1)+f(n-2).
*/
