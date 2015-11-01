/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

struct node
{
	string val;
	string path;
	int level;	
	node(string a, string b, int c)
	{
		val = a;
		path = b;
		level = c;
	}			
};


class Solution 
{

	public:

	void build_graph(unordered_set<string>& wordList, unordered_map<string, unordered_set<string> >& graph)
	{
		for(unordered_set<string>::iterator it = wordList.begin(); it != wordList.end(); it++)
		{
			string p = *it;
			graph[p] = unordered_set<string>();

			string q = p;
			for(int i = 0; i < p.length(); i++)
    	{
           	char ch = p[i];
          	for(int j = 0; j < 26; j++)
           	{
                   	p[i] = j+'a';
                  	if(wordList.find(p) != wordList.end())
                    {
          						graph[q].insert(p);                                        	        
          					}

                    p[i] = ch;
              }
			}	
		}	
	}

	vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) 
	{
		wordList.insert(beginWord);
		wordList.insert(endWord);
		unordered_map<string, unordered_set<string> > graph;
		build_graph(wordList, graph);

		wordList.insert(endWord);
		vector<vector<string> > result;
		
		int min_level = -1;
		node p(beginWord, beginWord, 0);
				
		queue<node> my_queue;
		my_queue.push(p);

		while(my_queue.size() > 0)
		{
			node p = my_queue.front();
			my_queue.pop();
			if(min_level != -1 && p.level > min_level)
			{
				break;
			}
			else if(p.val == endWord)
			{
				if(min_level == -1)
					min_level = p.level;
				stringstream scin(p.path);
				string s;
				vector<string> v;
				while(scin >> s)
				{
					v.push_back(s);
				}		
				result.push_back(v);	
			}			
			else
			{
				for(unordered_set<string>::iterator it = graph[p.val].begin(); it != graph[p.val].end(); it++)
				{
					if(p.path.find(*it) == string::npos)
					{
						node q(*it, p.path+" "+*it, p.level+1);
            my_queue.push(q);
					}
				}
			}
		}
		return result;					
	}

};

/*
  用广度优先搜索枚举路径，将字典生成一个图，遍历时不用逐位更换字符串，看图的相邻结点。
  图中结点为字符串，相邻结点为改变字符串一位所得的字符串。
  但是超时，以后再做。
*/
