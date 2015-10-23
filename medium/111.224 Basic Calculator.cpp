/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
*/

#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution 
{

	public:

	
	stack<int> sym;
	vector<int> record;
	int calculate(string s) 
	{
		if(s.length() == 0)
			return 0;
		sym = stack<int>();
		record = vector<int>();
		int count = 0;
		for(int i = 0; i < s.length(); i++)
		{
			record.push_back(-1);
			if(s[i] == '(')
				sym.push(i);	
			else if(s[i] == ')')
			{
				int x = sym.top();
				sym.pop();
				record[x] = i;	
			}
		}

		return get_result(s, 0, s.length()-1);
	}

	int get_result(string& s, int begin, int end)
	{
		int result = 0;
		int flag = -1;
		for(int i = begin; i <= end; i++)
		{
			int j = i;
			while(j <= end && s[j] == ' ')
				j++;
			if(j > end)
				break;
			if(s[j] == '(')
			{
				int r = get_result(s, j+1, record[j]-1);
				if(flag == -1)
					result = r;
				else if(flag == 1)
					result = result + r;
				else
					result = result - r;	
				i = record[j];
			}		
			else if(s[j] == '+')
			{
				flag = 1;
				i = j;
			}	
			else if(s[j] == '-')
			{
				flag = 2;
				i = j;
			}
			else
			{
				int b = j;
				j++;
				while(j <= end && s[j] >= '0' && s[j] <= '9')
					j++;
				int k = stoi(s.substr(b, j-b));
				if(flag == -1)
                                        result = k;
                                else if(flag == 1)
                                        result = result + k;
                                else
                                        result = result - k;
				i = j-1;	
			}
		}	
		return result;
	}	
};

int main()
{
	Solution s;
	string st;
	while(cin >> st)
	{
		cout << s.calculate(st) << endl;	
	}	
	return 0;
}

/*
  使用一个栈来记录每个括号的位置，然后依次计算。
*/
