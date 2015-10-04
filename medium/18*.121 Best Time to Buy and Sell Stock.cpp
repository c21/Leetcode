/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

class Solution 
{

	public:

    	int maxProfit(vector<int>& prices) 
	{
		
        
		return maxProfit(prices, 0, prices.size()-1);	
    	}

	int get_max(vector<int>& array, int begin, int end)
	{	
		if(begin >= end)
			return 0;
		else if(begin + 1 == end)
		{
			return max(array[end] - array[begin], 0);
		}	
		else
		{
			int mid = (begin+end)/2;
			int r1 = get_max(array, begin, mid);
			int r2 = get_max(array, mid+1, end);

			int min_p = array[mid];
			int max_p = array[mid+1];
			for(int i = begin; i < mid; i++)
			{
				if(min_p > array[i])
					min_p = array[i];
			}				
			for(int i = mid+2; i <= end; i++)
			{
				if(max_p < array[i])
					max_p = array[i];
			}

			int r3 = max_p - min_p;
			return max(max(max(r1,r2),r3),0);
		}
	}
};

/*
  分治，选取中间元素，分三种情况求最大值：1.买卖都出现在前半段 2.买卖都出现在后半段 3.买在前半段，卖在后半段。
  复杂度为O(nlogn), 这题有O(n)的方法，以后再做。
*/
