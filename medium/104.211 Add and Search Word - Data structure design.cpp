/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cassert>
using namespace std;

struct node
{
	node* next[26];
	int flag;
};


class WordDictionary 
{
	
	node* root;
	
	public:

	WordDictionary()
	{
		root = (node*)malloc(sizeof(node));
//		memset(root, 0, sizeof(root));
		for(int i = 0; i < 26; i++)
			root->next[i] = NULL;
		root->flag = 0;			
	}

	// Adds a word into the data structure.
	void addWord(string word) 
	{
		node* p = root;
		for(int i = 0; i < word.length(); i++)
		{
			if(p->next[word[i]-'a'] == NULL)
			{
		//		cout << word[i] << endl;
				node* q = (node*)malloc(sizeof(node));
//				memset(q, 0, sizeof(q));
				for(int j = 0; j < 26; j++)
                        		q->next[j] = NULL;
				q->flag = 0;
				p->next[word[i]-'a'] = q;
				p = q;
			}
			else
				p = p->next[word[i]-'a'];	
		}			
		p->flag = 1;	
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) 
	{
//		assert(root);
		return str_search(word, root, 0);
	}

	bool str_search(string& word, node* p, int begin)
	{
//		cout << "begin:" << begin << endl;
		if(p == NULL)
			return false;
		else if(p->flag == 1 && begin == word.length())
			return true;
		else if(begin == word.length())
			return false;
		else
		{
			if(word[begin] == '.')
			{
				for(int i = 0; i < 26; i++)
				{
					if(p->next[i] != NULL && str_search(word, p->next[i], begin+1))
					{
						return true;
					}
				}
			}
			else
			{
//				cout << "now" << endl;
				if(p->next[word[begin]-'a'] != NULL)
				{
//					cout << "here\n";
					return str_search(word, p->next[word[begin]-'a'], begin+1);
				}
			}
			
			return false;	
		}			
	}
};



// Your WordDictionary object will be instantiated and called as such:

// WordDictionary wordDictionary;

// wordDictionary.addWord("word");

// wordDictionary.search("pattern");


int main()
{
	WordDictionary wordDictionary;	
	wordDictionary.addWord("bad");
	wordDictionary.addWord("dad");
	wordDictionary.addWord("");
	 wordDictionary.addWord("dad");
	cout << wordDictionary.search("pad") << endl;
	cout << wordDictionary.search("bad") << endl;
	cout << wordDictionary.search(".ad") << endl;
	cout << wordDictionary.search("") << endl;

	return 0;
}

/*
  使用trie, 下面为使用哈希表实现trie.
*/
class myNode
{
    public:
    unordered_map<char, myNode*> map;
    int flag;
    myNode()
    {
        flag = 0;
    }
};

class WordDictionary 
{
    myNode* root = new myNode();
    public:

    // Adds a word into the data structure.
    void addWord(string word) 
    {
        myNode* p = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(p->map.find(word[i]) == p->map.end())
            {
                p->map[word[i]] = new myNode();
            }
            p = p->map[word[i]];
        }
        p->flag = 1;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) 
    {
        if(word == "")
            return false;
        else
            return find(word, 0, root);
    }
    
    bool find(string word, int k, myNode* p)
    {
        if(k == word.length()-1)
        {
            if(word[k] == '.')
            {
                for(unordered_map<char, myNode*>::iterator it = p->map.begin(); it != p->map.end(); it++)
                {
                    if(it->second->flag)
                        return true;
                }
                return false;
            }
            else
            {
                if(p->map.find(word[k]) != p->map.end())
                    return p->map[word[k]]->flag == 1;
                else
                    return false;
            }
        }   
        if(word[k] == '.')
        {
            for(unordered_map<char, myNode*>::iterator it = p->map.begin(); it != p->map.end(); it++)
            {
                if(find(word, k+1, it->second))
                    return true;
            }
            return false;
        }
        else
        {
            if(p->map.find(word[k]) != p->map.end())
                return find(word, k+1, p->map[word[k]]);
            else
                return false;
        }
    }
};
