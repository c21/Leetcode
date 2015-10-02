/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

*/

#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Solution 
{
	public:
	
	int titleToNumber(string s) 
	{
		int sum = 0;
		int len = s.length();
		for(int i = 0; i < s.length(); i++)
		{
			sum += (s[i]-'A'+1)*pow(26,len-i-1);	
		}	
		return sum;	
        }

};

int main()
{
	Solution s;
	string str;
	cin >> str;
	cout << s.titleToNumber(str) << endl;
	return 0;		
}

/*
  模拟
*/
