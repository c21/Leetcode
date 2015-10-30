/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

class Solution 
{

	public:

	vector<string> wordBreak(string s, unordered_set<string>& wordDict) 
	{
		if(s.length() == 0 || wordDict.size() == 0)
			return vector<string>();

		vector<bool> record(s.length()+1, false);
		vector<string> result;
		for(int i = s.length()-1; i >= 0; i--)
		{
			string s1 = s.substr(i, s.length()-i);
			if(wordDict.find(s1) != wordDict.end())
				record[i] = true;
			else
			{
				for(int j = i+1; j < s.length(); j++)
				{
					s1 = s.substr(i, j-i);
					if(wordDict.find(s1) != wordDict.end() && record[j])
					{
						record[i] = true;
						break;
					}		
				}		
			}
		}
		record[s.length()] = true;
		string path;
		search(s, wordDict, record, path, 0, result);
		return result;	
	}

	void search(string s, unordered_set<string>& wordDict, vector<bool>& record, string path, int k,
		vector<string>& result)
	{
		if(k == s.length())
		{
			result.push_back(path);			
		}
		else
		{
			for(int i = k+1; i <= s.length(); i++)
			{
				string s1 = s.substr(k, i-k);
				if(wordDict.find(s1) != wordDict.end() && record[i])
				{
					if(path == "")
						search(s, wordDict, record, s1, i, result);
					else
						search(s, wordDict, record, path+" "+s1, i, result);	
				}		
			}	
		}	
	}
};

/*
  这道题一开始超时。
  先用动态规划判断i-n是否可以word break.
  然后递归来枚举求解。
*/
