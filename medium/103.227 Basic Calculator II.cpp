/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
*/

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution 
{

	public:

	int calculate(string s) 
	{
		vector<int> num = vector<int>();
		vector<char> op = vector<char>();
		vector<int> flag = vector<int>();
		for(int i = 0; i < s.length(); i++)
		{
			int begin = i;
			while(begin < s.length() && s[begin] == ' ')
				begin++;
			if(begin < s.length() && s[begin] >= '0' && s[begin] <= '9')
			{
				int end = begin;
				while(end < s.length() && s[end] >= '0' && s[end] <= '9')	
					end++;
				num.push_back(stoi(s.substr(begin, end-begin)));	
				flag.push_back(1);
				i = end-1;	
			}		
			else if(begin < s.length() && (s[begin] == '+' || s[begin] == '-'
				|| s[begin] == '*' || s[begin] == '/'))
			{ 
				op.push_back(s[begin]);
				i = begin;	
			}
		}		

		if(op.size() == 0)
			return num[0];

		vector<int> n_num = vector<int>();
		vector<int> n_op = vector<int>();
		for(int i = 0; i < op.size(); i++)
		{
			if(op[i] == '*' || op[i] == '/')
			{
				int j = i;
				int new_num;
				while(j < op.size() && (op[j] == '*' || op[j] == '/'))
				{
					if(op[j] == '*')
						new_num = num[j]*num[j+1];
					else
						new_num = num[j]/num[j+1];
					num[j+1] = new_num;
					j++;
				}	
				n_num.push_back(new_num);
				flag[j] = -1;
				i = j-1;
			}
			else
			{
				if(flag[i] != -1)
					n_num.push_back(num[i]);
				if(i == op.size()-1)
					n_num.push_back(num[i+1]);
			}	
		}		

/*
		cout << "num: ";
                for(int i = 0; i < num.size(); i++)
                        cout << num[i] << " ";
                cout << endl;	
		cout << "op: ";
                for(int i = 0; i < op.size(); i++)
                        cout << op[i] << " ";
                cout << endl;
		cout << "flag: ";
                for(int i = 0; i < flag.size(); i++)
                        cout << flag[i] << " ";
                cout << endl;
		cout << "n_num: ";
		for(int i = 0; i < n_num.size(); i++)
			cout << n_num[i] << " ";
		cout << endl;
*/		int result = n_num[0];
		int next = 1;
		for(int i = 0; i < op.size(); i++)
		{
			if(op[i] == '+')
			{
				result = result + n_num[next];
				next++; 
			}
			else if(op[i] == '-')
			{
				result = result - n_num[next];
				next++;
			}
		}		

		return result;	
	} 

};

int main()
{
	Solution s;
	string str;
	while(cin >> str)
	{
		cout << s.calculate(str) << endl;
	}		
	return 0;
}

/*
  记录所有的数和操作符，先从左到右处理所有的乘除，再从左到右处理剩下所有的加减
*/
