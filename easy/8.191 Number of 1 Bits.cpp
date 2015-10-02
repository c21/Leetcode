/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/

#include <cstdio>

using namespace std;

class Solution 
{
	public:
	int hammingWeight(uint32_t n) 
	{
		int sum = 0;
		while(n > 0)
		{
			if(n % 2 == 1)
				sum++;
			n = n / 2;
		}	
		return sum;	
        }

};

int main()
{
	int n;
	scanf("%d", &n);
	Solution s;
	printf("%d\n", s.hammingWeight(n));
	return 0;		
}

/*  
  模拟
*/
