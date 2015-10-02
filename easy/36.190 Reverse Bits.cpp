/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer

*/

#include <stdint.h>
#include <cstring>
#include <cstdio>
using namespace std;

class Solution 
{

	public:

    	uint32_t reverseBits(uint32_t n) 
	{
		uint32_t bit[32];
		memset(bit, 0, sizeof(bit));
		
		uint32_t k = n;
		int count = 0;
		while(k > 0)
		{
			bit[count] = k % 2;
			k /= 2;
			count++;	
		}	
		
		uint32_t ans = 0;
		for(int i = 0; i <= 31; i++)
			ans = bit[i] + ans*2;
		return ans;				
    	}

};

int main()
{
	Solution s;
	int n;
	while(scanf("%d", &n) == 1)
	{
		printf("%d\n", s.reverseBits(n));
	}
	return 0;
}

/*
  模拟。
  注意uint32_t运算时，最好都使用uint32_t, 不要习惯性用int.
*/
