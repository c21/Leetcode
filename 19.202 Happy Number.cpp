/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

class Solution 
{
	public:

 	bool isHappy(int n) 
	{

		// to record the number appeared
		map<int, int> my_map = map<int,int>();
		
		while(n != 1)
		{
			if(my_map.find(n) != my_map.end())
				return false;
			my_map[n] = 1;
						
			int sum = 0;
			int k = n;
			while(k > 0)
			{
				sum += (k % 10)*(k % 10);
				k /= 10;
			}
			n = sum;	
		}
					
		return true;		
    	}

};

/*
  模拟
*/
