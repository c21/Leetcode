/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.  
*/

class Solution 
{

	public:

    	bool isValid(string s) 
	{
		// use stack to check 
		stack<char> my_stack = stack<char>();

		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == '(' || s[i] == '{'|| s[i] == '[')
				my_stack.push(s[i]);
	
			else if(s[i] == ')')
			{
				if(my_stack.size() == 0)
					return false;
				else
				{
					char ch = my_stack.top();
					my_stack.pop();
					if(ch != '(')
						return false;	
				}
			}	

			else if(s[i] == '}')    
                        {
                                if(my_stack.size() == 0)
                                        return false;
                                else
                                {
                                        char ch = my_stack.top();
                                        my_stack.pop();
                                        if(ch != '{')
                                                return false;
                                }
                        }
			
			else if(s[i] == ']')    
                        {
                                if(my_stack.size() == 0)
                                        return false;
                                else
                                {
                                        char ch = my_stack.top();
                                        my_stack.pop();
                                        if(ch != '[')
                                                return false;
                                }
                        }	
		}				
		
		if(my_stack.size() != 0)
			return false;
		else
			return true;
    	}

};

/*
  使用栈来模拟。
*/
