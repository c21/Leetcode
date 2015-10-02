/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution 
{

	public:

    	vector<string> summaryRanges(vector<int>& nums) 
	{
		
		vector<string> r = vector<string>();

		if(nums.size() == 0)
			return r;

		string s;
		for(int i = 0; i < nums.size(); i++)
		{
			if(i == 0)
			{
				s = to_string(nums[i]);
			}
			else if(nums[i] != nums[i-1]+1)
			{
				if(s != to_string(nums[i-1]))
					s += "->" + to_string(nums[i-1]);
				r.push_back(s);
                                s = to_string(nums[i]);
			}
		}
		if(s != to_string(nums[nums.size()-1]))
			s += "->" + to_string(nums[nums.size()-1]);
		r.push_back(s);
		return r;				
    	}

};

/*
  模拟
*/
