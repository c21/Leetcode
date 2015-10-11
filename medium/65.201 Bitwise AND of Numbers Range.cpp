/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/

class Solution 
{

	public:

	int rangeBitwiseAnd(int m, int n) 
	{
		if(m == 0 || n == 0)
			return 0;
		int sum = 0;
		int r1 = log2(m);
		int r2 = log2(n);
		while(r1 == r2)
		{
			sum += pow(2, r1);
			m -= pow(2, r1);
			n -= pow(2, r2);
			if(m == 0 || n == 0)
				break;
			r1 = log2(m);
			r2 = log2(n);
		}		
		return sum;
	}

};

/*
  计算[m, n]的按位与，从m和n的最高位开始比较，保留那些都是1的位置，作为最终的和。
  如果一旦某一位开始m为0，n为1，那么从这一位到最低位的按位与必定为0，因为从0abcde-1fghij中必定会出现100000.
*/
