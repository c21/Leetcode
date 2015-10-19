/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Solution 
{

	public:

	int evalRPN(vector<string>& tokens) 
	{
		stack<string> my_stack = stack<string>();

		if(tokens.size() == 0)
			return 0;

		for(int i = 0; i < tokens.size(); i++)
		{
			int l1, l2;
			if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				int l2 = stoi(my_stack.top());
				my_stack.pop();
				int l1 = stoi(my_stack.top());
				my_stack.pop();
	
				if(tokens[i] == "+")
					my_stack.push(to_string(l1+l2));
				else if(tokens[i] == "-")
					my_stack.push(to_string(l1-l2));
				else if(tokens[i] == "*")
                                        my_stack.push(to_string(l1*l2));
				else if(tokens[i] == "/")
                                        my_stack.push(to_string(l1/l2));
			}	
			else
				my_stack.push(tokens[i]);

			
		}		
		return stoi(my_stack.top());	
	}

};

/*
  使用栈来模拟。
*/
