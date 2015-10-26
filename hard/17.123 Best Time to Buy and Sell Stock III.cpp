/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution 
{

	public:

	int maxProfit(vector<int>& prices) 
	{
		if(prices.size() == 0)
			return 0;
		vector<vector<vector<int> > > record = vector<vector<vector<int> > >();
		for(int i = 0; i < prices.size(); i++)
		{
			record.push_back(vector<vector<int> >());
			for(int j = 0; j <= 1; j++)
			{
				record[i].push_back(vector<int>());
				for(int k = 0; k <= 2; k++)
				{
					record[i][j].push_back(0);
				}
			}	
		}		

		for(int i = prices.size()-1; i >= 0; i--)
		{
			if(i == prices.size()-1)
			{
				record[i][0][0] = 0;
				record[i][0][1] = 0;
				record[i][1][0] = prices[i];
				record[i][1][1] = prices[i];
			}
			else
			{
				record[i][0][0] = max(record[i+1][0][0], record[i+1][1][0]-prices[i]);
				record[i][0][1] = max(record[i+1][0][1], record[i+1][1][1]-prices[i]);
				record[i][1][0] = max(record[i+1][1][0], record[i+1][0][1]+prices[i]);
				record[i][1][1] = max(record[i+1][1][1], record[i+1][0][2]+prices[i]);
			}	
		}	
		return record[0][0][0];
	}

};

/*
  动态规划。
  设f(i,j,k)为从第i天起，已买(j=1)或未买(j=0)，已交易次数为k的最大收益。
  f(i,0,0/1) = max(f(i+1,0,0/1), f(i+1,1,0/10-p[i]))
  f(i,0,2) = 0
  f(i,1,0/1) = max(f(i+1,1,0/1), f(i+1,0,1/2)+p[i])
*/
