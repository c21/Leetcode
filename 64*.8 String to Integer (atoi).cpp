/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

class Solution 
{

	public:
	
    	int myAtoi(string str) 
	{
    		double num = 0;
		if(str.length() == 0)
			return 0;

		int b1 = 0;
		while(b1 < str.length() && str[b1] == ' ')
			b1++;
		if(b1 == str.length())
			return 0;

		if(str[b1] != '+' && str[b1] != '-' && !(str[b1]>='0'&& str[b1]<='9'))		
			return 0;
		int flag = 1;
		if(str[b1] == '+')
			b1++;
		else if(str[b1] == '-')
		{
			flag = -1;
			b1++;
		}	
		if(!(str[b1]>='0'&& str[b1]<='9'))
			return 0;
		int e1 = b1;
		long long max = pow(2,31)-1;
                long long min = -pow(2,31);
		while(e1 < str.length() && str[e1]>='0'&& str[e1]<='9')
		{
			num = num*10 + (str[e1]-'0');
			
			e1++;
		}
		num = num*flag;
		if(num < min)
			return min;
		else if(num > max)
			return max;
		else
			return num;	
	}

};

/*
  使用long long会溢出，改用double.
*/
