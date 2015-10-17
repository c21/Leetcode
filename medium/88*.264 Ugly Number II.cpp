/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

class Solution 
{

	public:

	int nthUglyNumber(int n) 
	{
		if(n == 1)
			return 1;

		int i1 = 0, i2 = 0, i3 = 0;
		vector<int> r = vector<int>();
		r.push_back(1);
		for(int i = 2; i <= n; i++)
		{
			int x = min(r[i1]*2, min(r[i2]*3,r[i3]*5));
			r.push_back(x);
			if(x == r[i1]*2)
				i1++;
			if(x == r[i2]*3)
				i2++;
			if(x == r[i3]*5)
				i3++;	
		}		
		return r[n-1];				
	}

};

/*
  这题没有做出来。
  看了答案发现是每次从包含最少2,3,5的数中取一个最小的。
*/
