/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution 
{

	public:

    	int singleNumber(vector<int>& nums) 
	{
		unordered_map<int,int> my_map = unordered_map<int,int>();

		for(int i = 0; i < nums.size(); i++)
		{
			if(my_map.find(nums[i]) == my_map.end())
				my_map[nums[i]] = 1;
			else
				my_map[nums[i]]++;
		}	
		for(unordered_map<int,int>::iterator p = my_map.begin(); p != my_map.end(); p++)
		{
			if(p->second != 3)
				return p->first;
		}
        

    	}

};

/*
  使用hashing空间复杂度为O(n), O(1)空间复杂度需要将每个数的每个数位取模。
*/

/*
	假设每个整数都为32位，那么除掉加上那个数以外，每位上的和应该为3的倍数。
	即统计所有数的每个数位上的和，除以3余数，即为该数。
*/

class Solution 
{
    public:	
    int singleNumber(vector<int>& nums) 
    {
    	vector<int> bit(32, 0);
    	for(int i = 0; i < nums.size(); i++)
    	{
    		for(int j = 0; j < 32; j++)
    		{
    			bit[j] += ((nums[i] >> j) & 1);
    		}
    	}
    	int n = 0;
    	for(int i = 31; i >= 0; i--)
    	{
    		bit[i] = bit[i] % 3;
    		n = n*2 + bit[i];
    	}
    	return n;
    }
};


