/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution 
{

	public:

	
	bool isMatch(string s, string p) 
	{
		vector<vector<bool> > record(s.length()+1, vector<bool>(p.length()+1, false));
	
		int count = 0;
		for(int i = 0; i < p.length(); i++)
		{
			if(p[i] != '*')
				count++;
		}	
		if(count > s.length())
			return false;
		for(int i = s.length(); i >= 0; i--)
		{
			for(int j = p.length(); j >= 0; j--)
			{
				if(i == s.length())
				{
					if(j == p.length())
						record[i][j] = true;
					else
            record[i][j] = (p[j] == '*' && record[i][j+1]);
				}
				else
				{	
					if(j == p.length())
            record[i][j] = false;
      		else
      		{
        		if(p[j] == '?')
              record[i][j] = record[i+1][j+1];
        		else if(p[j] == '*')
              record[i][j] = record[i][j+1] || record[i+1][j];
        		else
              record[i][j] = (s[i] == p[j] && record[i+1][j+1]);
      		}
				}
			}
		}	
		return record[0][0];						
	} 

};

/*
  动态规划。
  设f(i,j)为s[i...n]和p[j...m]是否可以匹配。
  如果按照从后往前顺序进行填空，则有：
  f(i,j) = 
    1. f(i+1,j+1)                   如果p[j] = '?'
    2. f(i+1,j) || f(i,j+1)         如果p[j] = '*'
    3. s[i] == p[j] && f(i+1,j+1)   其他
    
  注意可以有一个剪枝：先判断p中非*个数是否大于s字符个数，如果大于，那么返回false.
*/
