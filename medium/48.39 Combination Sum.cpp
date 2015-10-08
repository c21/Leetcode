/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution 
{

	public:

	vector<vector<int> > combinationSum(vector<int>& candidates, int target) 
	{
		sort(candidates.begin(), candidates.end());

		vector<vector<int> > result = vector<vector<int> >();
		
		if(candidates.size() == 0)
			return result;
		else
		{
			sort(candidates.begin(), candidates.end());
			vector<int> flag = vector<int>();
			for(int i = 0; i < candidates.size(); i++)
				flag.push_back(0);
			get_combin(result, candidates, flag, 0, target);
			return result;
		}	
    	}

	void get_combin(vector<vector<int> >& result, vector<int>& array, vector<int>& flag, int begin, int t)
	{
		if(t == 0)
		{
			vector<int> r = vector<int>();
                        for(int i = 0; i < flag.size(); i++)
                     	{
                         	for(int j = 1; j <= flag[i]; j++)
                                 	r.push_back(array[i]);
                    	}
                   	result.push_back(r);
		}
		else if(begin < array.size())
		{
			if(array[begin] <= t)
			{
				for(int i = 0; i*array[begin] <= t; i++)
				{
					flag[begin] = i;
					get_combin(result, array, flag, begin+1, t-i*array[begin]);
					flag[begin] = 0;
				}	 
			}
		}
			
	}

};


int main()
{
	Solution s;
	vector<int> c = vector<int>();
	int t;
	int n;
	while(scanf("%d", &t) == 1)
	{
		while(scanf("%d", &n) == 1)
		{
			c.push_back(n);
		}
		vector<vector<int> > r = s.combinationSum(c, t);
		for(int i = 0; i < r.size(); i++)
		{
			for(int j = 0; j < r[i].size(); j++)
				printf("%d ", r[i][j]);
			printf("\n");
		}
	}
	return 0; 
}

/*
  深度优先搜索。
*/
