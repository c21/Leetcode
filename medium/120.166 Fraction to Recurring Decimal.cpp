/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/

#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Solution 
{

	public:

	string fractionToDecimal(int numerator, int denominator) 
	{
		unordered_map<long long, int> my_map = unordered_map<long long,int>();

		int flag = 1;
		if((numerator >= 0) != (denominator >= 0))
			flag = -1;
		long long x = abs((long long)numerator);
		long long y = abs((long long)denominator);
		string s = "";
		if(x == 0)
			return "0";

		long long p = x / y;
		long long r = x % y;
		string s2 = to_string(p);
		s += s2;		
		int place = s2.length() + 1;
		if(r != 0)
		{
			s += ".";
		}	
		x = r * 10;
		int w_flag = 0;
		while(x != 0)
		{
			while(x < y)
			{
				if(my_map.find(x) != my_map.end())
				{
					int pi = my_map[x];
                                        string s1 = s.substr(0, pi);
                                        string s2 = s.substr(pi, s.length()-pi);
                                        s = s1 + "(" + s2 + ")";
					w_flag = 1;
                                        break;
				}
				else
					my_map[x] = place;
				x = x * 10;
				s += "0";	
				place++;
			}
			if(w_flag)
				break;
			long long p = x / y;
			long long r = x % y;
			if(r == 0)
			{
				string s2 = to_string(p);
				s += s2;
				place = place + s2.length();
			}	
			else
			{
				if(my_map.find(x) != my_map.end())
				{
					int pi = my_map[x];
					string s1 = s.substr(0, pi);
					string s2 = s.substr(pi, s.length()-pi);
					s = s1 + "(" + s2 + ")";
					break;	
				}
				else
				{
					my_map[x] = place;
					string s2 = to_string(p);
					s += s2;
					place = place + s2.length();
				}
			}
			x = r*10;	
		}
		if(flag == -1)
			return "-" + s;
		else	
			return s;						
	}

};

int main()
{
	Solution s;
	int x, y;
	while(cin >> x >> y)
	{
		cout << s.fractionToDecimal(x, y) << endl;
	}	
	return 0;
}

/*
  不断模拟手动除法，记录每次被除数，当出现循环停止。
  需要注意的点：
  1.溢出
  2.负数
  -2147483648 / -1 = 2147483648
*/
