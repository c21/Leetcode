/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/


class Solution 
{

	public:

	int candy(vector<int>& ratings) 
	{
		if(ratings.size() == 0)
			return 0;
	
		vector<int> candy(ratings.size(), 1);
		for(int i = 1; i <= ratings.size()-1; i++)
		{
			if(ratings[i] > ratings[i-1])
				candy[i] = candy[i-1]+1;
		}		
		for(int i = ratings.size()-2; i >= 0; i--)
		{
			if(ratings[i] > ratings[i+1])
				candy[i] = max(candy[i], candy[i+1]+1);
		}
		int sum = 0;
		for(int i = 0; i < ratings.size(); i++)
			sum += candy[i];
		return sum;
	}

};

/*
  这题没想出来。
  方法是先从左到右扫描一遍，检查每个数是否比左边数大，如果是，则糖果数加一
  再从右到左扫描一遍，检查每个数是否比右边数大，如果是，则糖果数加一
*/
