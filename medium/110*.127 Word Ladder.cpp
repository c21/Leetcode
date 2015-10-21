/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

class Solution 
{

	public:

	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) 
	{
		unordered_map<string, int> visit = unordered_map<string, int>();
		wordList.insert(endWord);

		queue<pair<string, int> > my_queue = queue<pair<string, int> >();	
		my_queue.push(make_pair(beginWord, 1));
		while(my_queue.size() > 0)
		{
			pair<string, int> p = my_queue.front();
			s = p.first;
			visit[s] = 1;
			my_queue.pop();
			if(s == endWord)
				return p.second;
			
			for(int i = 0; i < s.length(); i++)
			{
				char ch = s[i];
				for(int j = 0; j < 26; j++)
				{
					s[i] = j+'a';	
					if(wordList.find(s) != wordList.end() && visit.find(s) == visit.end())
					{
						wordList.erase(s);
						my_queue.push(make_pair(s, p.second+1));
					}	
				} 
				s[i] = ch;
			}
		}		
		return 0;				
	}

};

/*
  这题可以用广度优先搜索来求最短路径，有几点必须注意。
  1.需要将endWord加入字典。
  2.搜索时逐位改变当前字符串，并且从字典中删除已遍历的字符串。
  3.广度优先搜索时记录已用的变换次数。
*/
