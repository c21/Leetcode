/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

class Solution 
{


	public:

	int longestValidParentheses(string s) 
	{
		if(s.length() == 0)
			return 0;

		stack<pair<char,int> > my_stack = stack<pair<char,int> >();
		int max_len = 0;
		for(int i = 0; i < s.length(); i++)
		{
			
			if(my_stack.size() > 0 && my_stack.top().first == '(' && s[i] == ')')
			{
				my_stack.pop();
				if(my_stack.size() > 0)
          max_len = max(max_len, i-my_stack.top().second);
        else
          max_len = max(max_len, i+1);	
			}
			else
				my_stack.push(make_pair(s[i], i));

				
		}				
		return max_len;
	}

};

/*
  一开始试了一下枚举，
  从每个元素开始，依次向右扫描一遍，用栈来记录最长长度，时间复杂度为O(n^2)，超时。
  然后，想可以用O(n)的方法，扫描一次，记录每个元素的值和位置。
  每当匹配成功，看一下栈顶元素的位置i, 就代表从i+1到当前位置肯定是一个合法序列。
*/
