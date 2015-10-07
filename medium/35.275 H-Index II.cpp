/*
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
*/

class Solution 
{

	public:

    	int hIndex(vector<int>& citations) 
	{
/*
		if(citations.size() == 0)
			return 0;

		for(int i = 0; i < citations.size(); i++)
		{
			if(citations.size()-i <= citations[i])
				return citations.size()-i;	
		}		
        	return citations[citations.size()-1];
*/
		if(citations.size() == 0)
			return 0;
		else
			return get_h(citations, 0, citations.size()-1);	
    	}

	int get_h(vector<int>& array, int begin, int end)
	{
		if(begin == end)
		{
		  if(array.size()-begin < array[begin])
		    return array.size()-begin;
		  else
		    return array[begin];
		}
		else if(begin < end)
		{
			int mid = (begin+end)/2;
			if(array.size()-mid > array[mid])
				return get_h(array, mid+1, end);
			else
				return get_h(array, begin, mid);	
		}	
	}

};

/*
  折半搜索找到n-i <= a[i]的最小的i的点。
*/
