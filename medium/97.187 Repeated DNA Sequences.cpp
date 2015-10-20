/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/

class Solution 
{

	public:

	vector<string> findRepeatedDnaSequences(string s) 
	{
		unordered_map<string, int> map = unordered_map<string, int>();
		vector<string> r = vector<string>();
		
		if(s.length() <= 10)
			return r;
		for(int i = 0; i <= s.length()-10; i++)
		{
			string sub_s = s.substr(i, 10);
			if(map.find(sub_s) == map.end())
				map[sub_s] = 1;
			else if(map[sub_s] == 1)
			{
				r.push_back(sub_s);
				map[sub_s]++;
			}
		}			
		return r;
	}

};

/*
  模拟
*/
