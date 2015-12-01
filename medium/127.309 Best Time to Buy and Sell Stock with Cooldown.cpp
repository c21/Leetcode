/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/

class Solution 
{
    public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size() == 0)
            return 0;
        vector<pair<int,int> > f(prices.size()+1, make_pair(0, 0));
        for(int i = prices.size()-1; i >= 0; i--)
        {
            if(i == prices.size()-1)
            {
                f[i].first = 0;
                f[i].second = prices[i];
            }
            else
            {
                f[i].first = max(f[i+1].first, f[i+1].second-prices[i]);
                f[i].second = max(f[i+1].second, f[i+2].first+prices[i]);
            }
        }     
        return f[0].first;
    }
};

/*
  动态规划
  f(i,0/1): 代表从i-n天手上不/持有股票的最大收益
  f(i,0) = max(f(i+1,0), f(i+1,1) - p[i])
  f(i,1) = max(f(i+1,1), f(i+2,0) + p[i])
*/
