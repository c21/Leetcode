/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

class Queue 
{
	
	stack<int> s_end;	// store the second part of queue, which is reversed
        stack<int> s_begin;	// store the first part of queue, which is in order
	
	public:
	Queue()
	{
		s_end = stack<int>();
		s_begin = stack<int>();
	}
	
	// Push element x to the back of queue.
	void push(int x) 
	{
		s_end.push(x);					
        }



	// Removes the element from in front of queue.
	void pop(void) 
	{

		// if the first part of queue is not empty, just pop the first one
		if(!s_begin.empty())
			s_begin.pop();
		// else, pop all second part of queue, then push them into first part queue, them pop the first one
		else		
		{
			while(!s_end.empty())
			{
				int x = s_end.top();
				s_begin.push(x);
				s_end.pop();
			}
			s_begin.pop();	
		}
        }

	// Get the front element.
	int peek(void) 
	{
   		// if the first part of queue is not empty, just get the first one
		if(!s_begin.empty())
			return s_begin.top();
		// else, pop all second part of queue, then push them into first part queue, then get the first one
		else
		{
			while(!s_end.empty())
                        {
				int x = s_end.top();
                                s_begin.push(x);
                                s_end.pop();
                        }
                        return s_begin.top();
		}	 
	}

	// Return whether the queue is empty.
	bool empty(void) 
	{
		return s_begin.empty() && s_end.empty();	
    	}

};

/*
  用两个栈来模拟链表，一个栈来模拟链表后半部分(逆序)，另一个栈来模拟链表前半部分(顺序)
  对于任何一个元素，执行操作，最多被push2次，pop2次。
*/
