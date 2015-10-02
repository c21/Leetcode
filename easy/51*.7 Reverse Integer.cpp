/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.  
*/

class Solution 
{

	public:

    	int reverse(int x) 
	{
    		int flag = 1;
		if(x < 0)
		{
			x = -x;
			flag = -1;
		}
		long long result = 0;
		long long k = x;
		while(k > 0)
		{
			result = result*10 + (k%10);
			k /= 10;
		}
		result = flag*result;
		if(result < -(pow(2,31)-1) || result > pow(2,31)-1)
			return 0;
		else
			return result;
	}

};

/*
  翻转int整数有可能溢出，关于整数的操作需要考虑溢出的情况。
  int最小值为-(2^(31)-1), 最大值为2^(31)-1
*/
