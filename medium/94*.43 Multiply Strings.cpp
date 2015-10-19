/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class Solution 
{

	public:

	string multiply(string num1, string num2) 
	{
		string r = "";
		if(num1.length() == 0 || num2.length() == 0)
			return r;
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		
		int* digit = (int*)malloc(sizeof(int)*(num1.length()+num2.length()+10));
//		memset(digit, 0, sizeof(digit));
		for(int i = 0; i < num1.length()+num2.length()+10; i++)
			digit[i] = 0;
		for(int i = 0; i < num1.length(); i++)
		{
			for(int j = 0; j < num2.length(); j++)
			{
				digit[i+j] += (num1[i]-'0')*(num2[j]-'0');		
			}
		}

		int carry = 0;
		int end;
		for(int i = 0; i < num1.length()+num2.length()+10; i++)
		{
			if(digit[i] + carry >= 10)
			{
				int new_carry = (digit[i]+carry) / 10;
				digit[i] = (digit[i]+carry) % 10;
				carry = new_carry;
			}	
			else
			{
				digit[i] = digit[i]+carry;
				carry = 0;	
			}
			if(digit[i] != 0 || i == 0)
				end = i;
		}
					
		for(int i = 0; i <= end; i++)
			r += (digit[i]+'0');
		reverse(r.begin(), r.end());
		return r;							
	}

};

int main()
{
	Solution s;
	string s1, s2;
	while(cin >> s1 >> s2)
	{
		cout << s.multiply(s1, s2) << endl;
	}	
	return 0;
}

/*
  这题没有想出来。
  答案的方法是按照乘法的方法，对于每一位进行两数相乘，记录结果，然后进行进位，注意去掉末尾的0。
  以及一开始倒转字符串会比较方便写。
  注意：用malloc, memset在leetcode上会有问题。
*/
