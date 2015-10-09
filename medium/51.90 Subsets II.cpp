/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution 
{

	public:

  vector<vector<int> > subsetsWithDup(vector<int>& nums) 
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
				int count = 1;
				while(j < nums.size() && nums[i] == nums[j])
				{
					count++;
					j++;
				}
				record.push_back(pair<int,int>(nums[i], count));
				flag.push_back(0);
				i = j-1;	
			}
	
			gen_set(record, flag, 0, result);

			return result;
		}	
	}

	void gen_set(vector<pair<int,int> >& record, vector<int>& flag, int k, vector<vector<int> >& result)
	{
		if(k == record.size())
		{
			vector<int> r = vector<int>();
			for(int i = 0; i < flag.size(); i++)
			{
				for(int j = 1; j <= flag[i]; j++)
					r.push_back(record[i].first);
			}
			result.push_back(r);	
		}
		else 
		{
			for(int i = 0; i <= record[k].second; i++)
			{
				flag[k] = i;
				gen_set(record, flag, k+1, result);
				flag[k] = 0;
			}	
		}	
	}

};

/*
  枚举
*/
