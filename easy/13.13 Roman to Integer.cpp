/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

class Solution 
{
	public:
	
	int romanToInt(string s) 
	{
		int r[26];
		memset(r, 0, sizeof(r));
		r['I'-'A'] = 1;
		r['V'-'A'] = 5;
		r['X'-'A'] = 10;
		r['L'-'A'] = 50;
		r['C'-'A'] = 100;
		r['D'-'A'] = 500;
		r['M'-'A'] = 1000;
			
		int sum = 0;		
		for(int i = 0; i < s.length(); i++)
		{
			if(i == s.length()-1)
				sum += r[s[i]-'A'];
			else
			{
				if(r[s[i]-'A'] < r[s[i+1]-'A'])
				{
					sum += r[s[i+1]-'A'] - r[s[i]-'A'];
					i++;
				}
				else
				{
					sum += r[s[i]-'A'];
				}
			}		
		}			
		return sum;
	}

};

int main()
{
	Solution s;
	string str;
	cin >> str;
	printf("%d\n", s.romanToInt(str));
	return 0;			
}

/*
  这题要知道罗马数字的表示方法，如果存在两位：IV,VL之类，得到的数为4，45
*/
