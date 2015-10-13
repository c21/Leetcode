/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

class Solution 
{

	public:

	vector<vector<int> > permuteUnique(vector<int>& nums) 
	{
		vector<vector<int> > result = vector<vector<int> >();
		if(nums.size() == 0)
			return result;
		else
		{
			sort(nums.begin(), nums.end());
			vector<pair<int,int> > record = vector<pair<int,int> >();
			vector<int> flag = vector<int>();
			for(int i = 0; i < nums.size(); i++)
			{
				int j = i+1;
				while(j < nums.size() && nums[j] == nums[i])
					j++;
				record.push_back(pair<int,int>(nums[i], j-i));		
				i = j-1;
			}	
			for(int i = 0; i < nums.size(); i++)
				flag.push_back(0);
		
			gen_per(result, record, flag, 0);			
		}			
	}

	void gen_per(vector<vector<int> >& result, vector<pair<int,int> >& record, vector<int>& flag, int k)
	{
		if(k == flag.size())
		{
			result.push_back(flag);	
		}
		else
		{
			for(int i = 0; i < record.size(); i++)
			{
				if(record[i].second > 0)
				{
					record[i].second--;
					flag[k] = record[i].first;
					gen_per(result, record, flag, k+1);
					record[i].second++;
				}
			}	
		}
	}
};


int main()
{
	Solution s;
	vector<int> r = vector<int>();
	int k;
	while(scanf("%d", &k) == 1)
	{
		r.push_back(k);
	}
	vector<vector<int> > x = s.permuteUnique(r);
     	for(int i = 0; i < x.size(); i++)
      	{
        	for(int j = 0; j < x[i].size(); j++)
                   	printf("%d ", x[i][j]);
            	printf("\n");
    	}
	return 0;	
}

/*
  枚举，记录下每个数的出现次数，每次按照数的剩余可用次数来枚举。
*/
