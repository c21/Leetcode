/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.
*/


class Solution 
{

	public:

	vector<vector<string> > groupAnagrams(vector<string>& strs) 
	{
		vector<vector<string> > result = vector<vector<string> >();
		if(strs.size() == 0)
			return result;
		
		int flag[26];

		vector<pair<string,string> > r = vector<pair<string,string> >();

		for(int i = 0; i < strs.size(); i++)
		{
			string s = strs[i];
			memset(flag, 0, sizeof(flag));
			for(int j = 0; j < s.length(); j++)
			{
				flag[s[j]-'a']++;	
			}
			// generate new string
			string t_s = "";
			for(int i = 0; i < 26; i++)
				t_s += to_string(flag[i])+".";
			r.push_back(pair<string,string>(t_s, s));				
		}		

		sort(r.begin(), r.end());
		for(int i = 0; i < r.size(); i++)
		{
			vector<string> this_r = vector<string>();
			this_r.push_back(r[i].second);
			int j = i+1;
			while(j < r.size() && r[j].first == r[i].first)
			{
				this_r.push_back(r[j].second);
				j++;
			}	
			i = j-1;
			result.push_back(this_r);
		}	
		return result;	
	}

};

/*
  记录每个字符串的26个字母的出现次数，转换成字符串形式，然后排序。
*/
