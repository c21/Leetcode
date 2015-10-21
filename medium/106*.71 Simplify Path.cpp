/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

class Solution 
{

	public:

	string simplifyPath(string path) 
	{
		stack<string> my_stack = stack<string>();
	
		for(int i = 0; i < path.size(); i++)
		{
			int b = i;
			while(b < path.size() && path[b] == '/')	
				b++;
			if(b >= path.size())
				break;
			int e = b;
			while(e < path.size() && path[e] != '/')
				e++;
			string s = path.substr(b, e-b);
			if(s == "..")
			{
				if(my_stack.size() > 0)
					my_stack.pop();
			}	
			else if(s != ".")
				my_stack.push(s);
			i = e-1;
		}		
		if(my_stack.size() == 0)
			return "/";	
		string r = "";
		while(my_stack.size() > 0)
		{
			r = "/" + my_stack.top() + r;		
			my_stack.pop();
		}
		return r;
	}

};

/*
  这题没有想出来。
  答案方法是：使用一个栈来保存目录
  先忽略所有的/ 
  如果得到.., 就返回上级目录，出栈一个元素
  如果得到., 就停留在本级目录，什么也不做
  否则，压栈一个新目录。
*/
