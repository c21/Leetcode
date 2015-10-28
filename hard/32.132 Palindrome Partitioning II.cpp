/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution {
public:
    	int minCut(string s) 
	{
		if(s.length() == 0 || s.length() == 1)
			return 0;
		
		vector<vector<bool> > p(s.length(), vector<bool>(s.length(),false));
		vector<int> record(s.length(), -1);
	
	
		// get all palindrome
		for(int i = s.length()-1; i >= 0; i--)
		{
			for(int j = i; j <= s.length()-1; j++)
			{
				if(i == j)
					p[i][j] = true;
				else if(i+1 == j)
					p[i][j] = (s[i] == s[j]);
				else
					p[i][j] = (s[i] == s[j] && p[i+1][j-1]); 	
			}
		}		
	
		// get minimal cut
		for(int i = s.length()-1; i >= 0; i--)
		{
			if(p[i][s.length()-1])
				record[i] = 0;
			else
			{
				int min_val = s.length()-1-i;
				for(int j = i+1; j <= s.length()-1; j++)
				{
					if(p[i][j-1])
						min_val = min(min_val, record[j]+1);
				}
				record[i] = min_val;
			}	
		}	
		return record[0];
	}
};

/*
  动态规划。
  设f(i)为切s[i-n]的最小次数，p(i,j)代表s[i-j]是否为回文
  f(i) =  0                               若p(i,n) == true
        min(1+f(j)) | p(i,j-1) == true    否则
  
  p(i,j) =  ture                          若i == j
            s[i] == s[j]                  若i+1 == j
            s[i] == s[j] && p(i+1,j-1)    否则
        
*/
