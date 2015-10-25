/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution 
{

	public:

	int minDistance(string word1, string word2) 
	{
		vector<vector<int> > record = vector<vector<int> >();
		for(int i = 0; i < word1.size(); i++)
		{
			record.push_back(vector<int>());
			for(int j = 0; j < word2.size(); j++)
				record[i].push_back(-1);
		}	

		return get_min(0, 0, word1, word2, record);		
	}

	int get_min(int b1, int b2, string& word1, string& word2, vector<vector<int> >& record)
	{
		if(b1 >= word1.length() && b2 >= word2.length())
			return 0;
		else if(b1 >= word1.length() && b2 < word2.length())
			return word2.length()-b2;
		else if(b1 < word1.length() && b2 >= word2.length())
			return word1.length()-b1;
		else if(record[b1][b2] != -1)
			return record[b1][b2];
	
		int r1 = 1 + get_min(b1, b2+1, word1, word2, record);
		int r2 = 1 + get_min(b1+1, b2, word1, word2, record);
		int r3;
		if(word1[b1] == word2[b2])
			r3 = get_min(b1+1, b2+1, word1, word2, record);
		else
			r3 = 1+ get_min(b1+1, b2+1, word1, word2, record);
		record[b1][b2] = min(r1, min(r2, r3));
		return record[b1][b2];						
	}	
};

/*
  动态规划。
  f(i, j) 代表w1[i...]转换为w2[j...]的最少次数
  f(i, j) = 
          1. 1+f(i,j+1)
      min 2. 1+f(i+1, j)
          3. f(i+1,j+1)  if w1[i] == w2[j]
            1+f(i+1,j+1) o.w.
*/
