/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

class Solution 
{

	public:

    	bool isIsomorphic(string s, string t) 
	{
		map<char, char> my_map = map<char, char>();
		map<char, int> use = map<char, int>();
		for(int i = 0; i < s.length(); i++)
		{
			if(my_map.find(s[i]) == my_map.end())
			{
				if(use.find(t[i]) == use.end())
				{
					use[t[i]] = 1;
					my_map[s[i]] = t[i];
				}
				else
					return false;
			}
			else
			{
				if(my_map[s[i]] != t[i])
					return false;
			}
		}	
		return true;
	}
};

/*  
  注意看题目，需要按顺序，并且不能两个字符映射到相同的字符
*/
