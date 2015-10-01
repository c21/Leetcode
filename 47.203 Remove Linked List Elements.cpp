/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution 
{

	public:

    	string longestCommonPrefix(vector<string>& strs) 
	{
		if(strs.size() == 0)
			return "";	
		int p = 1;
		string s = "";
		while(1)
		{
			for(int i = 0; i < strs.size(); i++)
			{
				if(p > strs[i].length() || strs[i][p-1] != strs[0][p-1])
					return s;
				
			}		
			s = s + strs[0][p-1];
			p++;	
		}
		return s;	
    	}

};

/*
  模拟
*/
