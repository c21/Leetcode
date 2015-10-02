/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution 
{

	public:

    	string countAndSay(int n) 
	{
		if(n == 1)
			return "1";
		else
		{
			string s = "1";
			for(int i = 2; i <= n; i++)
			{
				string new_s = "";
				for(int j = 0; j < s.size(); j++)
				{
					int count = 1;
					int k = j+1;
					while(k < s.size() && s[k] == s[j])
					{
						count++;
						k++;
					}
					int ch = count+'0';
					new_s = new_s + (char)ch+s[j];
					j = k-1;	
				}
				s = new_s;	
			}
			return new_s;
		}	
    	}

};

/*
  模拟
*/
