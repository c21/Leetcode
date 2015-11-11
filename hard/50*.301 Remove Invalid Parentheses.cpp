/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/


class Solution 
{
    public:
    vector<string> removeInvalidParentheses(string s)
    {
    	unordered_set<string> set;
    	vector<string> r;
    	queue<string> my_queue;
    	my_queue.push(s);
    	set.insert(s);
    	bool find = false;
    	while(my_queue.size() > 0)
    	{
    		string p = my_queue.front();
    		my_queue.pop();
    		if(is_valid(p))
    		{
    			find = true;
    			r.push_back(p);
    		}
    		if(find)
    			continue;
    		for(int i = 0; i < p.length(); i++)
    		{
    			if(p[i] == '(' || p[i] == ')')
    			{
    				string q = p.substr(0, i) + p.substr(i+1, s.length()-i-1);
    				if(set.find(q) == set.end())
    				{
    					my_queue.push(q);
    					set.insert(q);
    				}
    			}
    		}
        }
        return r;
    }

    bool is_valid(string s)
	{
		stack<char> my_stack;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == ')' && my_stack.size()>0 && my_stack.top() == '(')
				my_stack.pop();
			else if(s[i] == '(' || s[i] == ')')
				my_stack.push(s[i]);
		}
		return my_stack.size() == 0;
	}
	
};


/*
  这题没有想出来。
  用的解法是枚举，逐个去掉符号，查看是否是合法的字符串。
  用广度优先搜索，保证找到最少去掉次数的解法。巧妙的地方是进行层数的判断。
  当搜到合法的那一层时，就不往下搜了，往下搜的肯定不是最少去掉次数的答案。
*/
