/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

class TrieNode 
{
	public:
	TrieNode* next[26];
	int flag;
	// Initialize your data structure here.
	TrieNode() 
	{
		for(int i = 0; i < 26; i++)
			next[i] = NULL;	
		flag = 0;
	}

};



class Trie 
{

	public:
	
	
	Trie() 
	{
		root = new TrieNode();
	}


	// Inserts a word into the trie.
	void insert(string word) 
	{
		int begin = 0;
		TrieNode* p = root;
		for(int i = 0; i < word.length(); i++)
		{
			if(p->next[word[i]-'a'] == NULL)
			{
				p->next[word[i]-'a'] = new TrieNode(); 
			}	
			p = p->next[word[i]-'a'];
		}
		if(p != NULL)
			p->flag = 1;
	}



	// Returns if the word is in the trie.
	bool search(string word) 
	{
		TrieNode* p = root;
		for(int i = 0; i < word.length(); i++)
		{
			if(p->next[word[i]-'a'] == NULL)
				return false;
			p = p->next[word[i]-'a'];	
		}
		return p->flag == 1;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) 
	{
		TrieNode* p = root;
		for(int i = 0; i < prefix.length(); i++)
                {
                        if(p->next[prefix[i]-'a'] == NULL)
                                return false;
                        p = p->next[prefix[i]-'a'];
                }
		return true;
	}



	public:

	TrieNode* root;

};

class Solution 
{

	public:

	vector<string> findWords(vector<vector<char> >& board, vector<string>& words) 
	{
		Trie trie;
		for(int i = 0; i < words.size(); i++)
		{
			trie.insert(words[i]);
		}

		set<string> result;
		if(board.size() == 0 || board[0].size() == 0 || words.size() == 0)
			return vector<string>();

		vector<vector<int> > flag(board.size(), vector<int>(board[0].size(), 0));

		for(int i = 0; i < board.size(); i++)
		{
			for(int j = 0; j < board[i].size(); j++)
			{
				flag[i][j] = 1;
				string path = ""+board[i][j];
				if(trie.startsWith(path))
					search(board, trie, result, flag, path, i, j);	
				flag[i][j] = 0;
			}	
		}				
		vector<string> r;
		for(set<string>::iterator p = result.begin(); p != result.end(); p++)
		{
			r.push_back(*p);
		}	
		return r;
	}


	int dic_x[4] = {0, -1, 0, 1};
	int dic_y[4] = {-1, 0, 1, 0};

	void search(vector<vector<char> >& board, Trie& trie, 
			set<string>& result, vector<vector<int> >& flag, string path, int x, int y)
	{
		if(trie.search(path))
		{
			result.insert(path);
		}		
		for(int i = 0; i < 1; i++)
		{
			int new_x = x + dic_x[i];
			int new_y = y + dic_y[i];
			if(new_x >= 0 && new_x < board.size() && new_y >= 0 && new_y < board[new_x].size()
			&& flag[new_x][new_y] == 0)
			{
				char ch = board[new_x][new_y];
		    	if(trie.startsWith(path+""+ch))
				{
					flag[new_x][new_y] = 1;
					search(board, trie, result, flag, path+ch, new_x, new_y);
					flag[new_x][new_y] = 0;
				}
			}	
		}		
	}

};


/*
  使用字典树来存储字典，该代码一直runtime error, 不知为何。
*/
