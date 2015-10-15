/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
    	bool wordBreak(string s, unordered_set<string>& wordDict) 
	{			
	
		map<pair<int,int>, bool> my_map = map<pair<int,int>, bool>();	
		if(s == "")
		{
			if(wordDict.find(s) == wordDict.end())
				return false;
			else
				return true;
		}
		else
			return find(s, wordDict, 0, s.length()-1, my_map);	
	}
	
	bool find(string& s, unordered_set<string>& wordDict, int begin, int end, map<pair<int,int>, bool>& my_map)
	{
		pair<int,int> p = pair<int,int>(begin, end);
		if(my_map.find(p) != my_map.end())
			return my_map[p];
		string sub_s = s.substr(begin, end-begin+1);
		if(wordDict.find(sub_s) != wordDict.end())
		{
			my_map[p] = true;
			return true;
		}
		else
		{
			for(int i = begin; i < end; i++)
			{
				sub_s = s.substr(begin, i-begin+1);
				if(wordDict.find(sub_s) != wordDict.end())
				{
					if(find(s, wordDict, i+1, end, my_map))
					{
						my_map[p] = true;
						return true;
					}
				}
			}
			my_map[p] = false;
			return false;
		}	
	}
};

/*
  一开始直接暴力搜索，超时了。
  后来用动态规划做，记录每个i, j的s[i...j]是否可以为单词。
  以后应该仔细想，如果可以用动态规划就用动态规划做。
*/
