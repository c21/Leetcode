/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

#include <cstdio>
#include <algorithm>

using namespace std;

class Solution 
{
	public:

    	int trailingZeroes(int n) 
	{
/*
		int count_2 = 0;
		int count_5 = 0;

		// record every number from(2-n) contains how many 2 and 5
		for(int i = 2; i <= n; i++)	
		{
			int k = i;
	
			while(k > 1 && k % 2 == 0)
			{
				count_2++;
				k /= 2;
			}	

			while(k > 1 && k % 5 == 0)
                        {
                                count_5++;
                                k /= 5;
                        }		
		}

        
	//	return min(count_2, count_5);
	//	return count_5;
*/
		long long x = n;
		long long f = 5;
		int count = 0;
		while(f <= x)
		{
			count = count + x/f;
			f = f * 5;			
		}	

		return count;	  
  	}

};

int main()
{
	Solution s;
	int n;
	while(scanf("%d", &n) == 1)
	{
		printf("%d\n", s.trailingZeroes(n));
	}	
	return 0;
}

/*
  这是道好题目。
  一开始想计算末尾的0的个数，就是计算n!是10的多少倍。
  但是不能直接计算n!, n!会很大，只能从1-n各个数来想。
  于是想到质因数分解，可以得到n!的质因数分解的表示。
  通过质因数分解，可以知道n!可以表示为(2^x)*(5^y)*...
  求n!是10的多少倍，等价于求min(x, y).
  
  一开始对1-n每个数i求i是2的多少倍，是5的多少倍，记录倍数，为O(nlogn), 超时。
  后来发现x必定大于或等于y, 因为每个偶数都是2的倍数，只需要记录每个数是5的多少倍即可，为O(nlogn), 超时。
  后来发现记录每个数是5的多少倍的简洁方法：n!/5为包含约数5的数个数，n!/(5^2)为包含约数25的数个数。
  依次类推，得到n!是5的多少倍 = (n!/5 + n!/(5^2) + n!/(5^3) + ... n!/(5^x)) (5^x <= n!, 5^(x+1) > n!)，为O(logn), 通过。
*/
