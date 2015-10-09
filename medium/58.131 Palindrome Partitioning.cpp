/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

class Solution 
{

	public:
	
	vector<vector<string> > partition(string s) 
	{
		vector<vector<string> > result = vector<vector<string> >();
		
		if(isPalindrome(s))
		{
			vector<string> r = vector<string>();
			r.push_back(s);
			result.push_back(r);
		}	

		for(int i = 0; i < s.length()-1; i++)
		{
			string s1 = s.substr(0, i+1);
			if(isPalindrome(s1))
			{
				vector<vector<string> > r1 = partition(s.substr(i+1, s.length()-i-1));
				for(int j = 0; j < r1.size(); j++)
				{
					vector<string> r = vector<string>();
					r.push_back(s1);
					for(int k = 0; k < r1[j].size(); k++)
						r.push_back(r1[j][k]);
					result.push_back(r);
				}	
			}				
		}	
		return result;	
	}

	bool isPalindrome(string& s)
	{
		if(s.length() == 0)
			return false;
		int begin = 0;
		int end = s.length()-1;
		while(begin <= end)
		{
			if(s[begin] != s[end])
				return false;
			begin++;
			end--;
		}	
		return true;		
	}
};

/*
  枚举。
  枚举开头的回文串，然后再枚举剩余的字符串情况。
*/
