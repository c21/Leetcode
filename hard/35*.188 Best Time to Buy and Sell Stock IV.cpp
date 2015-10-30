/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution 
{

	public:
	
	int maxProfit(int k, vector<int>& prices) 
	{
//		vector<vector<vector<int> > > record(prices.size(), vector<vector<int> >(2, vector<int>(k+1)));
		unordered_map<int, int> map0;
		unordered_map<int, int> map1;
		if(prices.size() == 0)
			return 0;
		if(k >= prices.size/2)
		{
			int f0 = 0;
			int f1 = 0;
			for(int i = prices.size()-1; i >= 0; i--)
			{
				if(i == prices.size()-1)
				{
					f0 = 0;
					f1 = prices[i];	
				}
				else
				{
					int r0 = max(f1-prices[i], f0);
					int r1 = max(f0+prices[i], f1);
					f0 = r0;
					f1 = r1;
				}
			}	
			return f0;
		}
		for(int i = prices.size()-1; i >= 0; i--)
		{
			for(int m = 0; m <= k; m++)
			{
				if(m == k)
					map0[m] = 0;
				else
				{
					if(i == prices.size()-1)
					{
						map0[m] = 0;
						map1[m] = prices[i];
					}
					else
					{
						int r0 = max(map1[m]-prices[i], map0[m]);
						int r1 = max(map0[m+1]+prices[i], map1[m]);
						map0[m] = r1;
						map1[m] = r1;
					}
				}
			}
/*
			for(int m = k; m >= 0; m--)	
			{
				if(m == k)
					record[i][0][m] = 0;
				else
				{
					if(i < prices.size()-1)
					{
						record[i][0][m] = max(record[i+1][1][m]-prices[i], record[i+1][0][m]);
						record[i][1][m] = max(record[i+1][0][m+1]+prices[i], record[i+1][1][m]);
					}
					else
					{
						record[i][0][m] = 0;
						record[i][1][m] = prices[i];
					}
				}
			}
*/
		}
		return map0[0];	
	}

};

/*
  动态规划。
  注意的是：
  如果k >= prices.size()/2, 那么相当于不限制次数，转换为二维的不限制次数的的问题。
  否则，设f(i, j, m)为已交易m次，当前已购(j=1)或未购(j=0)，从第i-n天的最大获益。
/*
