/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
Update (2015-06-11):
The class name of the Java function had been updated to MyStack instead of Stack.  
*/
class Stack {


	queue<int> q1;		// store the stack 
	queue<int> q2;		// store the stack
	
	
	public:

	Stack()
	{
		q1 = queue<int>();
		q2 = queue<int>();
	}

    	// Push element x onto stack.
	void push(int x) 
	{
		// push the element at the empty queue, and pop all elemets at another queue and push them all into this one
		queue<int>* r1;
		queue<int>* r2;
		
		if(q1.empty())	
		{
			r1 = &q1;
			r2 = &q2;
		} 
		else
		{
			r1 = &q2;
			r2 = &q1;
		}

		r1->push(x);
		
		while(!r2->empty())		
		{
			int n = r2->front();
			r2->pop();
			r1->push(n);
		}
    	}


    	// Removes the element on top of the stack.
    	void pop() 
    	{
		// remove the top element of the nonempty queue
		if(!q1.empty())
			q1.pop();
		else
			q2.pop();
	}



    	// Get the top element.
    	int top() 
	{
		// get the top element of the nonempty queue
		if(!q1.empty())
			return q1.front();
		else
			return q2.front();	
    	}



    	// Return whether the stack is empty.
    	bool empty() 
	{
		return q1.empty() && q2.empty();
    	}

};

/*
  可以用两个队列来模拟栈，不过效率比较低。push操作为O(n), pop,top,empty操作为O(1).
  push操作每次将新加入的元素移入空的队列头，将其他元素依次出队并进入该队列。
*/
