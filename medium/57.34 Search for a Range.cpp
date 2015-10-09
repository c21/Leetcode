/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution 
{

	public:

	vector<int> searchRange(vector<int>& nums, int target) 
	{
		vector<int> result = vector<int>();
		result.push_back(-1);
		result.push_back(-1);
		if(nums.size() == 0)
			return result;
		else
		{
			// find the begin		
			int begin = 0;
			int end = nums.size()-1;
			int p = -1;
			while(begin <= end)
			{
				int mid = (begin+end)/2;
				if(nums[mid] < target)
				{
					begin = mid+1;
				}	
				else if(target == nums[mid])
				{
					p = mid;
					end = mid-1;		
				}	
				else
				{
					end = mid-1;
				}
			}
			if(p != -1)
				result[0] = p;
			else
				return result;
			begin = 0;
			end = nums.size()-1;
			p = -1;
                        while(begin <= end)
                        {
                                int mid = (begin+end)/2;
                                if(nums[mid] > target)
                                {
                                        end = mid-1;
                                }
                                else if(target == nums[mid])
                                {
					p = mid;
                                        begin = mid+1;
                                }
				else
				{
					begin = mid+1;
				}
                        }
			result[1] = p;
			return result;	
		}
	}

	

};

/*
  折半搜索。
*/
