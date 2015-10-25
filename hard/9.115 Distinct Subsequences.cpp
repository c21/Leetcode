/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

class Solution 
{

	public:

	int numDistinct(string s, string t) 
	{
		if(s.length() == 0 || t.length() == 0 || s.length() < t.length())
			return 0;

	
		vector<vector<int> > record = vector<vector<int> >();
		vector<vector<int> > place = vector<vector<int> >();
		for(int i = 0; i < t.length(); i++)
		{
			record.push_back(vector<int>());
			place.push_back(vector<int>());
			for(int j = 0; j < s.length(); j++)
			{
				if(t[i] == s[j])
					place[i].push_back(j);
				record[i].push_back(-1);
			}
		}				

		return get_num(0, 0, record, place);		
	}

	int get_num(int begin_t, int begin_s, vector<vector<int> >& record, vector<vector<int> >& place)
	{
	
    if(begin_t >= record.size() || begin_s >= record[0].size())
      return 0;
		if(record[begin_t][begin_s] != -1)
			return record[begin_t][begin_s];

		if(begin_t == record.size()-1)
		{
			int sum = 0;
			for(int i = 0; i < place[begin_t].size(); i++)		
			{
				if(place[begin_t][i] >= begin_s)
				{
					sum++;
				}	
			}
			record[begin_t][begin_s] = sum;
		}
		else
		{
			int sum = 0;
			for(int i = 0; i < place[begin_t].size(); i++)
      {
        if(place[begin_t][i] >= begin_s)
        {
          sum += get_num(begin_t+1, place[begin_t][i]+1, record, place);
        }
      }
      record[begin_t][begin_s] = sum;
		}
		return record[begin_t][begin_s];
	}	
		

};

/*
  动态规划。
  f(j, i) 代表s[i...]和t[j...]的不同子序列数目
  f(j, i) = sum f(j+1,k+1)  | s[k] = t[j].
*/
