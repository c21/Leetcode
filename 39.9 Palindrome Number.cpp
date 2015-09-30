/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.
*/

#include <cmath>
#include <cstdio>

using namespace std;

class Solution 
{

	public:

    	bool isPalindrome(int x) 
	{
		if(x < 0)
			return false;
		// fist get the number of digits of x
		int num = 0;
		int k = x;
		while(k > 0)
		{
			num++;
			k /= 10;
		}		

		// compare the most and least significant digit
		k = x;
		for(int i = 1; i <= num/2; i++)
		{
			int l = k % 10;
			int h = k / pow(10, num-1-2*(i-1));
			if(h != l)
				return false;
			k = (k - h * (int)pow(10, num-1-2*(i-1))) / 10;
		}	
		return true;
        }

};


int main()
{
	Solution s;
	int n;
	while(scanf("%d", &n) == 1)
	{
		printf("%d\n", s.isPalindrome(n));
	}	
	return 0;
}

/*
  这道题一开始说不让使用额外空间，后来发现是可以使用常数空间。
  逐位比较即可。
*/
