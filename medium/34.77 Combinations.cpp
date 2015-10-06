/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include <vector>
#include <cstdio>

using namespace std;

class Solution 
{

	public:

	vector<vector<int> > result;

    	vector<vector<int> > combine(int n, int k) 
	{
		result = vector<vector<int> >();

		vector<int> flag = vector<int>();
		
		for(int i = 0; i < n; i++)
			flag.push_back(0);
	
		gen_comb(flag, 0, k);			
    	
		return result;
	}

	void gen_comb(vector<int>& flag, int begin, int k)
	{
		if(begin == flag.size())
		{
			vector<int> com = vector<int>();
			for(int i = 0; i < flag.size(); i++)
			{
				if(flag[i] == 1)
					com.push_back(i+1);
			}
			result.push_back(com);
		}
		else if(flag.size()-begin == k)
		{
			vector<int> com = vector<int>();
			for(int i = 0; i < flag.size(); i++)
			{
                                if( (i < begin && flag[i] == 1) || (i >= begin))
                                        com.push_back(i+1);
                        }
			result.push_back(com);	
		}
		else
		{
			flag[begin] = 0;
			gen_comb(flag, begin+1, k);
			if(k > 0)
			{
				flag[begin] = 1;
				gen_comb(flag, begin+1, k-1);	
			}
		}
	}
};

int main()
{
	Solution s;
	int n, k;
	while(scanf("%d %d", &n, &k) == 2)
	{
		vector<vector<int> > r = s.combine(n, k);
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
  模拟
*/
