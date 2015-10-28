/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution 
{

	public:

	bool isInterleave(string s1, string s2, string s3) 
	{
		if(s1.length() + s2.length() != s3.length())
			return false;
		if(s1.length() == 0 && s2.length() == 0 && s3.length() == 0)
			return true;

		vector<vector<int> > record = vector<vector<int> >();
		for(int i = 0; i <= s1.length(); i++)
		{
			record.push_back(vector<int>());
			for(int j = 0; j <= s2.length(); j++)
			{
				record[i].push_back(-1);
			}
		}
		return judge(s1, s2, s3, 0, 0, record);	
	}

	bool judge(string& s1, string& s2, string& s3, int i, int j, vector<vector<int> >& record)
	{
		
		if(i == s1.length() && j == s2.length())
		{
			record[i][j] = 1;
			return true;
		}
		else if(record[i][j] != -1)
		{
			if(record[i][j] == 1)
				return true;
			else
				return false;
		}
		else
		{
			int k = i+j;
			bool r = false;
			if(s1[i] == s3[k])
				r = r || judge(s1, s2, s3, i+1, j, record);
			if(s2[j] == s3[k])
				r = r || judge(s1, s2, s3, i, j+1, record);
			if(r == true)
				record[i][j] = 1;
			else
				record[i][j] = 0;
			return r;	
		}	
	}
};

/*
  动态规划。
  一开始想三维的f(i, j, k): s3[k-n3]能否为s1[i-n1]和s2[j-n2]交叉生成。
  后来发现i,j确定后,k必须为i+j. 所以可以用两维f(i,j)来表示：s3[(i+j)-n3]能否为s1[i-n1]和s2[j-n2]交叉生成。
  f(i,j) =  false 
            || f(i+1,j)  if s1[i] == s3[i+j]
            || f(i,j+1)  if s2[j] == s3[i+j].
*/
