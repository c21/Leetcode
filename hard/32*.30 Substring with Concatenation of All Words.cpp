/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).


*/

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution 
{

	public:

	vector<int> findSubstring(string s, vector<string>& words) 
	{
		vector<int> r;
		if(words.size() == 0 || s.length() == 0)
			return r;
		int w_len = words[0].length();
		int s_len = w_len * words.size();	
		if(w_len == 0 || s.length() < s_len)
			return r;
		
		unordered_map<string, int> map;
		for(int i = 0; i < words.size(); i++)
		{
			if(map.find(words[i]) == map.end())
				map[words[i]] = 1;
			else
				map[words[i]]++;
		}				

		for(int i = 0; i+s_len-1 <= s.length()-1; i++)
		{
			int j;
			unordered_map<string, int> map2 = map;
			for(j = 0; j < words.size(); j++)
			{
				string s1 = s.substr(i+j*w_len, w_len);
				if(map2.find(s1) == map2.end())
					break;
				else
				{
					int count = map2[s1];
					if(count == 0)
						break;
					else
						map2[s1] = count-1;
				}	
			}
			if(j == words.size())
				r.push_back(i);	
		}	
		return r;
	
	}

};

int main()
{
	Solution s;
	string s1;
	cin >> s1;
	string s2;
	vector<string> words;
	while(cin >> s2)
	{
		words.push_back(s2);
	}		
	vector<int> r = s.findSubstring(s1, words);
	for(int i = 0; i < r.size(); i++)
		cout << r[i] << " ";
	cout << "\n";
	return 0;	
}

/*
  这道题用枚举超时。
  答案的方法是，使用哈希表来存储所有单词。
  由于单词长度一样，只需要检查固定长度的字符串即可。
  这是道好题目，以后做题需要考虑是否可以用哈希表来存储字符串及其对应的出现次数。
*/
