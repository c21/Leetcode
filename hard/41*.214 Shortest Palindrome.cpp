/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/

class Solution 
{

	public:

	string shortestPalindrome(string s) 
	{
		if(s.length() == 0 || s.length() == 1)
			return s;
		
		string t = s + "#" + reverse(s.begin(), s.end());
		vector<int> p(t.length(), 0);
		for(int i = 1; i < p.size(); i++)
		{
			int j = p[i-1];
			while(j > 0 && t[i] != t[j])
			{
				j = p[j-1];
			}	
			if(t[i] == i[j])
				j++;
			p[i] = j;
		}		
		string s2 = s.substr(s.length()-p[p.size()-1]);
		reverse(s2.begin(), s2.end());
		return s2 + s;		
	}
};

/*
  这题没有想出来。用到了KMP，以后再做。
*/
