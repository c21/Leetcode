/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

*/

#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

class Solution 
{
	public:

	bool isAnagram(string s, string t) 
	{
		int r1[26];
		int r2[26];
		memset(r1, 0, sizeof(r1));
		memset(r2, 0, sizeof(r2));

		for(int i = 0; i < s.length(); i++)
			r1[s[i]-'a']++;
		for(int i = 0; i < t.length(); i++)
                        r2[t[i]-'a']++;

		for(int i = 0; i < 26; i++)
		{
			if(r1[i] != r2[i])
				return false;
		}		
		return true;
	}

};

int main()
{
	Solution s;
	string s1, s2;
	cin >> s1 >> s2;
	printf("%d\n", s.isAnagram(s1, s2));
	return 0;
}

/*
  模拟
*/
