/*
Implement a trie with insert, search, and startsWith methods.

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



	private:

	TrieNode* root;

};



// Your Trie object will be instantiated and called as such:

// Trie trie;

// trie.insert("somestring");

// trie.search("key");

/*
  首先要知道trie的定义。
  对于每个结点，分配26个子结点代表a-z.另外再加一个标志位，如果标志位为1，代表从树根到该结点形成的字符串为单词，
  否则，不为单词。
*/
