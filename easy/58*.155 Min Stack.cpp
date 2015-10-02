/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack 
{

	stack<int> my_stack;
	stack<int> min_stack;

	public:

	MinStack()
	{
		my_stack = stack<int>();
		min_stack = stack<int>();
	}

    	void push(int x) 
	{
		my_stack.push(x);

		if(min_stack.empty() || min_stack.top() >= x)
			min_stack.push(x);						
    	}



    	void pop() 
	{
		int x = my_stack.top();
		my_stack.pop();

		if(x == min_stack.top())
			min_stack.pop();
    	}



    	int top() 
	{
		return my_stack.top();
    	}



    	int getMin() 
	{
		return min_stack.top();	
    	}

};

/*
  这题没有想出来，是另外再建立一个栈来保存当前的最小值。
*/
