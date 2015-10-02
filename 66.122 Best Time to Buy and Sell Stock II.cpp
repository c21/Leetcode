/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution 
{

	public:

    	int maxProfit(vector<int>& prices) 
	{
	
		if(prices.size() == 0)
			return 0;

		vector<pair<int,int> > record = vector<pair<int,int> >();	
        	for(int i = 0; i < prices.size(); i++)
		{
			record.push_back(pair<int,int>());
			if(i == 0)
			{
				record[i].first = 0;
				record[i].second = -prices[i];
			}
			else
			{
				record[i].first = max(record[i-1].first, record[i-1].second+prices[i]);
				record[i].second = max(record[i-1].second, record[i-1].first-prices[i]);
			}
		}
		return record[prices.size()-1].first;

    	}

};

/*
  动态规划。
  设f(i, 0)为第0-i天不持有股票的最大获利
  f(i, 1)为第0-i天持有股票的最大获利。
  则有：
  f(i, 0) = max(f(i-1,0), f(i-1,1)+prices[i])
  f(i, 1) = max(f(i-1,1), f(i-1,0)-prices[i])
*/
