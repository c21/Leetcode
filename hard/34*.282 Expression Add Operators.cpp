/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

class Solution 
{

	public:

	vector<string> addOperators(string num, int target) 
	{
		vector<string> result;
		search(num, target, 0, 0, "", result);
		return result;		
	}
	
	void search(string num, int target, long long diff, long long curNum, string out, vector<string>& result)
	{
		if(num.length() == 0 && curNum == target)
			result.push_back(out);
		else
		{
			for(int i = 1; i <= num.length(); i++)
			{
				string cur = num.substr(0, i);
				string next = num.substr(i, num.length()-i);
				if(cur.size() > 1 && cur[0] == '0')
					return;
				if(out.length() > 0)
				{
					search(next, target, stoll(cur), curNum+stoll(cur), out+"+"+cur, result);
					search(next, target, -stoll(cur), curNum-stoll(cur),out+"-"+cur, result);
					search(next, target, diff*stoll(cur), (curNum-diff)+diff*stoll(cur), 
						out+"*"+cur, result);
					
				}
				else
				{
					search(next, target, stoll(cur), stoll(cur), cur, result);
				}
			}
		}	
	}

};

/*
  这题没有想出来，用的是递归加入符号，注意相乘的情况，每次记录变化值。以后再做。
*/
