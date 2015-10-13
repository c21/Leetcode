/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

class Solution 
{

	public:

	vector<vector<int> > combinationSum2(vector<int>& candidates, int target) 
	{	
		vector<vector<int> > result = vector<vector<int> >();
		if(candidates.size() == 0)
			return result;
		else
		{
			sort(candidates.begin(), candidates.end());
			vector<int> flag = vector<int>();
			vector<pair<int,int> > record = vector<pair<int,int> >();
			for(int i = 0; i < candidates.size(); i++)
			{
				int j = i+1;
				while(j < candidates.size() && candidates[j] == candidates[i])
				{
					j++;
				}
				record.push_back(pair<int,int>(candidates[i], j-i));
				i = j-1;
				flag.push_back(0);	
			}	
			gen_comb(record, flag, result, target, 0);			
			return result;
		}
	}

	void gen_comb(vector<pair<int,int> >& record, vector<int>& flag, vector<vector<int> >& result, int target, int k)
	{
		if(target == 0)
		{
			vector<int> r = vector<int>();
			for(int i = 0; i < flag.size(); i++)
			{
				for(int j = 0; j < flag[i]; j++)
					r.push_back(record[i].first);
			}
			result.push_back(r);	
		}
		else if(k < flag.size())
		{
			if(target >= record[k].first)
			{
				for(int i = 0; i*record[k].first <= target && i <= record[k].second; i++)
				{
					flag[k] = i;
					gen_comb(candidates, flag, result, target-i*record[k], k+1);
					flag[k] = 0;
				}
			}
		}
	}	
};

/*
  搜索，注意要记录每个数的出现次数，遇到有重复的数的情况都要小心考虑一下重复可能带来的影响。
*/
