/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

#include <vector>
#include <utility>
#include <cstdio>
#include <cmath>
using namespace std;

class Solution 
{

	public:

	int mySqrt(int x) 
	{
		long long begin = 0;
		long long end = x / 2+1;
		long long result;
		while(begin <= end)
		{
			long long mid = (begin+end)/2;
			long long n = mid*mid;
			if(n == x)
				return mid;
			else if(n > x)
			{
				end = mid-1;
			}	
			else
			{
				begin = mid+1;
			}
		}		
		return 	end;
	} 

};

int main()
{
	Solution s;
	int k;
	while(scanf("%d", &k) == 1)
	{
		printf("%d\n", s.mySqrt(k));
	}	
	return 0;
}

/*
  一开始用筛法求质因数分解，结果有问题。
  发现答案是确定平方根的范围是[0, x/2+1], 然后二分查找平方根。
*/
