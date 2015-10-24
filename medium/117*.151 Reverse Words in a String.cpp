/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

class Solution 
{

	public:

	void reverseWords(string &s) 
	{
		string word, s1 = "";
		stringstream scin(s);
		int first_time = 1;
		while(scin >> word)
		{
			if(first_time)
			{
				s1 = word;
				first_time = 0;
			}	
			else
				s1 = word + " " + s1;
		}
		s = s1;	
					
	}


};

/*
  模拟，为O(n)空间复杂度。以后再做。
*/
