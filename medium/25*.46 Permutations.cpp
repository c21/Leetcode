/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

class Solution 
{

	public:

	map<vector<int>, int> my_map;

	vector<vector<int> > result;	

	vector<int> g_num;

    	vector<vector<int> > permute(vector<int>& nums) 
	{
		my_map = map<vector<int>, int>();
		result = vector<vector<int> >();
		g_num = nums;

		vector<int> flag = vector<int>();					
       		for(int i = 0; i < nums.size(); i++)
			flag.push_back(0);
		vector<int> gen = nums;
		gen_permu(flag, 0, gen);	 
    		return result;
	}

	void gen_permu(vector<int>& flag, int x, vector<int>& gen)
	{
		if(x == flag.size())
		{
			if(my_map.find(gen) == my_map.end())
				result.push_back(gen);	
			my_map[gen] = 1;
		}	 
		else
		{
			for(int i = 0; i < flag.size(); i++)
			{
				if(flag[i] == 0)
				{
					flag[i] = 1;
					gen[x] = g_num[i];
					gen_permu(flag, x+1, gen);
					flag[i] = 0;
				}
			}
		}
	}

};

/*
  这题的数据应该是无重复元素的排列，对于有重复元素的排列以后再做。
*/
