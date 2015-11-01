#include <vector>
/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/

#include <string>
#include <iostream>

using namespace std;

class Solution 
{

	public:

	vector<string> fullJustify(vector<string>& words, int maxWidth) 
	{
		vector<string> result;
		for(int i = 0; i < words.size(); i++)
		{
			int len = words[i].length();
			int s_len = words[i].length();
			int j = i+1;
			while(j < words.size())
			{
				if(len + 1 + words[j].length() > maxWidth)
					break;
				len += 1 + words[j].length();
				s_len += words[j].length();
				j++;		
			}	
			int space_len = maxWidth - s_len;
			string s = "";
			if(j == words.size())
			{
				for(int k = i; k < j; k++)
				{
					if(k == i)
						s += words[k];
					else
						s += " " + words[k];		
				}
				string s1 = "";
				for(int k = s.length()+1; k <= maxWidth; k++)
					s1 += " ";
				s += s1;		
			}
			else
			{
				int count = j - i - 1;
				for(int k = i; k < j; k++)
				{
					if(k == i)	
						s += words[k];
					else
					{
						if(space_len % count == 0)
						{
							for(int a = 1; a <= space_len / count; a++)
								s += " ";	
							space_len = space_len - space_len / count;
						}	
						else
						{
							for(int a = 0; a <= space_len / count; a++)
								s += " ";
							space_len = space_len - space_len / count - 1;
						}
						count--;
						s += words[k];	
					}	
				}
				for(int k = 1; k <= space_len; k++)
					s += " ";	
			}

			result.push_back(s);
			i = j-1;
		}	
		return result;	
	}

};

int main()
{
	Solution s;
	int w;
	while(cin >> w)
	{
		vector<string> words;
		string str;
		while(cin >> str)
		{
			words.push_back(str);
		} 
		vector<string> r = s.fullJustify(words, w);
		for(int i = 0; i < r.size(); i++)
			cout << r[i] << "\n";		
	}	
	return 0;
}

/*
  对于每一行，用最少空一格来计算能放下的最多字符串。
  然后，对于空格每次尽量多取一个。
  如果末尾仍有未用完空格，需要加上空格。
*/
