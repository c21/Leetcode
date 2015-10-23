/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

class Solution {
public:
  unordered_map<int, int> map;
	vector<pair<int,int> > record;
	vector<vector<int> > threeSum(vector<int>& nums) 
	{
		vector<vector<int> > result = vector<vector<int> >();
		map = unordered_map<int,int>();
		if(nums.size() == 0)
			return result;
		else
		{
			sort(nums.begin(), nums.end());
			record = vector<pair<int,int> >();
			vector<int> flag = vector<int>();
			for(int i = 0; i < nums.size(); i++)
			{
				int j = i;
				while(j < nums.size() && nums[i] == nums[j])
					j++;
				record.push_back(make_pair(nums[i], j-i));
				flag.push_back(0);
				map[nums[i]] = record.size()-1;
				i = j-1;	
			}	
			vector<int> now = vector<int>();
			for(int i = 0; i < 3; i++)
				now.push_back(0);
			get_sum(result, flag, 0, 0, now);				
		}						
	}

	void get_sum(vector<vector<int> >& result, vector<int>& flag, int begin, int k, vector<int>& now)
	{
		if(k == 2)	
		{
			int c = now[0]+now[1];
			c = -c;
			if(c < now[1])
                    return;
			if(map.find(c) != map.end() && (1+flag[map[c]] <= record[map[c]].second))
			{
				vector<int> r = vector<int>();
				r.push_back(now[0]);
				r.push_back(now[1]);
				r.push_back(c);
				result.push_back(r);	
			}
		}
		else
		{
			int end;
			for(int i = begin; i < flag.size(); i++)
			{
				if(flag[i] < record[i].second)
				{
					flag[i]++;
					now[k] = record[i].first;
					get_sum(result, flag, i, k+1, now);
					flag[i]--;
				}	
			}	
		}
	}	
};

/*
  使用的方法是枚举前两个数，再用哈希表确定第三个数是否合法。
*/
