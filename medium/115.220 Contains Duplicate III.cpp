/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

class Solution 
{

	public:

	int numDecodings(string s) 
	{
		if(s.length() == 0)
			return 0;
		
		vector<int> v = vector<int>(s.length());
		for(int i = s.length()-1; i >= 0; i--)
		{
			if(i == s.length()-1)
			{
				if(s[i] != '0')
					v[i] = 1;
				else
					v[i] = 0;
			}
			else if(i == s.length()-2)
			{
				v[i] = 0;
				string st = s.substr(i, 2);
				int n = stoi(st);
				if(n >= 10 && n <= 26)
					v[i] = 1;
				if(s[i] != '0')
					v[i] += v[i+1];
			}
			else
			{
				v[i] = 0;
        string st = s.substr(i, 2);
        int n = stoi(st);
        if(n >= 10 && n <= 26)
          v[i] = v[i+2];
        if(s[i] != '0') 
		      v[i] += v[i+1];
			}
		}		
		return v[0];	
	}

};

/*
  动态规划。
  设f(i)为s[i-n]的解码方法
  如果s[i] != '0', f[i] += f[i+1], 如果s[i-(i+1)]组成10-26, f[i] += f[i+2].
*/
