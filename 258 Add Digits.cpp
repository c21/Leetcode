/*

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

*/

#include <cstdio>
using namespace std;  
class Solution 
{

	public:

    	int addDigits(int num) 
	{
		// add all the digits
		int sum = 0;
		while(num > 0)
		{
			sum = sum + (num % 10);
			num = num / 10;
		}		
		if(sum < 10)
			return sum;
		else
			return addDigits(sum);		
	}

};

int main()
{	
	int n; 
	Solution s; 
    	while(scanf("%d", &n) == 1)
     	{
      		printf("result: %d\n", s.addDigits(n));
     	}       
     	return 0;
}


/*
递归完成
*/
