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
  这题的数据应该是无重复元素的排列，处理有重复元素的排列如下所示。
*/

class Solution 
{
    public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
    	vector<vector<int> > r;
    	if(nums.size() == 0)
    		return r;
    	sort(nums.begin(), nums.end());
    	vector<pair<int,int> > flag;
    	for(int i = 0; i < nums.size(); i++)
    	{
    		int j = i+1;
    		while(j < nums.size() && nums[j] == nums[i])
    			j++;
    		flag.push_back(make_pair(nums[i], j-i));
    	}
    	vector<int> record(nums.size(), 0);
    	get_per(flag, r, 0, nums.size(), record);
	    return r;
     }

	void get_per(vector<pair<int,int> >& flag, vector<vector<int> >& r, int k, int n, vector<int>& record)
	{
		if(k == n)
		{
			r.push_back(record);
			return;
		}
		for(int i = 0; i < flag.size(); i++)
		{
			if(flag[i].second > 0)
			{
				flag[i].second--;
				record[k] = flag[i].first;
				get_per(flag, r, k+1, n, record);
				flag[i].second++;
			}
		}
	}
};


