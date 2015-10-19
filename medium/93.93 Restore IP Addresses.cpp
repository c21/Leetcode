/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class Solution 
{

	public:

	vector<string> restoreIpAddresses(string s) 
	{
		vector<string> result = vector<string>();
		if(s.length() == 0)
			return result;
		else
		{
			int flag[4];
			memset(flag, 0, sizeof(flag));
			get_ip(s, flag, result, 0);	
			return result;
		}	
	}

	void get_ip(string& s, int* flag, vector<string>& result, int k)
	{
		if(k == 3)
		{
			string x = s.substr(flag[2]+1, s.length()-1-flag[2]);
			if(x[0] == '0' && x.length() > 1)
				return;
			if(x.length() > 3)
				return;
			int a = stoi(x);
			if(!(a >= 0 && a <= 255))
				return;
			string this_s = "";
			for(int i = 0; i <= 2; i++)
			{
				if(i == 0)
					this_s = s.substr(0, flag[0]+1) + ".";
				else
					this_s += s.substr(flag[i-1]+1, flag[i]-flag[i-1]) + ".";
			}
			this_s += x;
			result.push_back(this_s);			
		}
		else if(k < 3)
		{
			int begin;
			if(k == 0)
				begin = 0;
			else
				begin = flag[k-1]+1;
			for(int i = begin; s.length()-1-i >= 3-k; i++)
			{
				if(i == begin && s[i] == '0')
				{
					flag[k] = i;
					get_ip(s, flag, result, k+1);
					break;	
				}
				string x = s.substr(begin, i-begin+1);
				if(x.length() > 3)
					break;
				int a = stoi(x);
				if(a >= 0 && a <= 255)
				{
					flag[k] = i;
					get_ip(s, flag, result, k+1);
					flag[k] = -1;
				}
				else
					break;
			}	
				
		}	
	}	
};


int main()
{
	Solution s;
	string str;
	while(cin >> str)
	{
		vector<string> r = s.restoreIpAddresses(str);
		for(int i = 0; i < r.size(); i++)
			cout << r[i] << endl;		
	}	
	return 0;
}

/*
  注意IP地址不能开头为0(除了0)，以及stoi可能会溢出的情况。
*/
