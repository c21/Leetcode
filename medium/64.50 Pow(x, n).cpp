/*
Implement pow(x, n).
*/

class Solution 
{

	public:

	double myPow(double x, int n) 
	{

		if(n == 0)
			return 1;
		else if(n > 0)
		{
			double r = myPow(x,n/2);
			if(n % 2 == 0)
				return r*r;
			else
				return r*r*x;
		}
		else
		{
			n = -n;
			double r = myPow(x,n/2);
			if(n % 2 == 0)
                                return 1.0/(r*r);
                        else
                                return 1.0/(r*r*x);	
		}	
/*
		if(n == 0)
			return 1;
		else if(n > 0)
		{
			double sum = 1;
			for(int i = 1; i <= n; i++)
				sum = x*sum;
			return sum;
		}	
		else
		{
			n = -n;
			double sum = 1;
			for(int i = 1; i <= n; i++)
				sum = sum*(1.0/x);
			return sum; 		
		}	
*/
	}

};

/*
  要折半计算。
*/
