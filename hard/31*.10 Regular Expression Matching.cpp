/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution 
{

	public:

	bool isMatch(string s, string p) 
	{
		if(s.length() == 0 && p.length() == 0)
			return true;
		else if(s.length() > 0 && p.length() == 0)
			return false;
		else
		{
			vector<vector<int> > record(s.length()+1, vector<int>(p.length(), -1));
		
			return match(s, p, 0, 0, record);
		}		
	}

	bool match(string& s, string& p, int i, int j, vector<vector<int> >& record)
	{
		if(i == s.length())
		{
			if(j == p.length())
				return true;
		}
			
		if(j == p.length())
			return false;
		if(record[i][j] != -1)
		{
			if(record[i][j] == 1)
				return true;
			else
				return false;
		}
		else
		{
			bool r = false;
			if(i == s.length())
			{
				if(j+1 < p.length() && p[j+1] == '*')
					r = r || match(s, p, i, j+2, record);
				else
					r = false;
				if(r == false)
					record[i][j] = 0;
				else
					record[i][j] = 1;
				return r;
			}
	
			if(p[j] == '.' || s[i] == p[j])
			{
				if(j+1 < p.length() && p[j+1] == '*')
				{
					r = r || match(s, p, i+1, j, record);
					r = r || match(s, p, i+1, j+2, record);
					r = r || match(s, p, i, j+2, record);
				}
				else
				{
					r = r || match(s, p, i+1, j+1, record);
				}
			}
			else
			{
				if(j+1 < p.length() && p[j+1] == '*')
					r = r || match(s, p, i, j+2, record);
				else
					r = false;
			}	
			if(r == false)
				record[i][j] = 0;
			else
				record[i][j] = 1;
			return r;
		}	
	}
};

int main()
{
	Solution s;
	string s1, s2;
	while(cin >> s1 >> s2)
	{
		cout << s.isMatch(s1, s2) << endl;
	}	
	return 0;
}

/*
  动态规划。
  设f(i, j)为s[i-n1]和p[j-n2]是否可以匹配。
  1.若i == n1+1
      若j == n2+1, f(i,j) = true
      否则，
          若j+1 <= n2 && p[j+1] == '*', f(i,j) = f(i,j+2)
          否则，f(i,j) = false
  2.若i <= n1
      若j == n2+1, f(i,j) = false
      否则，
          若p[j] == '.' || s[i] == p[j]
            若j+1 <= n2 && p[j+1] == '*', f(i,j) = f(i,j) || f(i+1,j) || f(i+1,j+2) || f(i,j+2)
            否则，f(i,j) = f(i,j) || f(i+1,j+1)
          否则
            若j+1 <= n2 && p[j+1] == '*', f(i,j) = f(i,j) || f(i,j+2)
            否则，f(i,j) = false
            
*/
