/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long x = -(1<<31);
        if(divisor == -1 && dividend == x)
            return ((1<<31)-1);
        long long dv = abs((long long)dividend);
		long long ds = abs((long long)divisor);

		int ans = 0;
		while(dv >= ds)
		{
			int h = 0;
			while(dv >= (ds<<h))
			    h++;
			dv = dv -   (ds << (h-1));
			ans = ans + (1 << (h-1));
		}	
		if((dividend >= 0) != (divisor >= 0))
			ans = -ans;
		return ans;		
    }
};

/*
  这题没有想出来。
  使用方法是不断左移除数。
*/
