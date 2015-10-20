/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class Solution 
{

	public:
	
	bool record[1010][1010];

	string longestPalindrome(string s) 
	{
		if(s.length() == 0 || s.length() == 1)
			return s;

		int max_len = -1;
		int begin = -1;
		int end = -1;
		memset(record, 0, sizeof(record));
		for(int l = 0; l <= s.length()-1; l++)
		{
			for(int i = 0; i+l <= s.length()-1; i++)
			{
				if(l == 0)
					record[i][i+l] = true;
				else if(l == 1)
				{
					if(s[i] == s[i+l])
						record[i][i+l] = true;
				}
				else
				{
					if(s[i] == s[i+l] && record[i+1][i+l-1])
						record[i][i+l] = true;		
				}
				if(record[i][i+l] && l+1 > max_len)
				{
					max_len = l+1;
					begin = i;
					end = i+l;
				}		
			}	
		}				
		
		return s.substr(begin, max_len);
	}
};


int main()
{
	Solution s;
	string st;
	while(cin >> st)	
	{
		cout << s.longestPalindrome(st) << endl;	
	}		
	return 0;
}

/*
  应该用动态规划的方法：
  d[i][j]代表从i到j是否为回文串
  d[i][i] = true
  当s[i] == s[i+1]时，d[i][i+1] = true
  当s[i] == s[j] 且 d[i+1][j-1] = true时，d[i][j] = true
*/
