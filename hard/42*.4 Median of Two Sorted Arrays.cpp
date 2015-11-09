/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

class Solution 
{

	public:
	
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		int m = nums1.size();
		int n = nums2.size();

		if((m+n) % 2 == 1)
		{
			return find(nums1, nums2, 0, m-1, 0, n-1, (m+n)/2+1);	
		}						
		else
		{
			double r1 = find(nums1, nums2, 0, m-1, 0, n-1, (m+n)/2);
			double r2 = find(nums1, nums2, 0, m-1, 0, n-1, (m+n)/2+1);
			return (r1+r2)*0.5;
		}

	}

	double find(vector<int>& nums1, vector<int>& nums2, int b1, int e1, int b2, int e2, int k)
	{
		if(e1-b1 > e2-b2)
		{
			return find(nums2, nums1, b2, e2, b1, e1, k);
		}	
		else if(b1 > e1)
		{
			return nums2[b2+k-1];
		}
		else if(k == 1)
		{
			return min(nums1[b1], nums2[b2]);
		}	
		else
		{
			if(e1-b1+1 >= k/2)
			{
				int p1 = k/2;
				int p2 = k-k/2;
				int x1 = nums1[b1+p1-1];
				int x2 = nums2[b2+p2-1];
				if(x1 == x2)
					return x1;
				else if(x1 < x2)
				{
					return find(nums1, nums2, b1+p1, e1, b2, e2, k-p1);	
				}	
				else
				{
					return find(nums1, nums2, b1, e1, b2+p2, e2, k-p2);
				}	
			}
			else
			{
				int m = e1-b1+1;
				int p1 = m;
				int p2 = k-m;
				int x1 = nums1[b1+p1-1];
				int x2 = nums2[b2+p2-1];
				if(x1 == x2)
					return x1;
				else if(x1 < x2)
				{
					return find(nums1, nums2, b1+p1, e1, b2, e2, k-p1);
				}			
				else
				{
					return find(nums1, nums2, b1, e1, b2+p2, e2, k-p2);
				}
			}	
		}	
	}
};

/*
  这题没有想出来。
  方法是求两个排好序数组的中位数，等价于求两个排好序数组(大小为m,n)的第(m+n)/2或第(m+n)/2+1个数。
  等价于求给定k, 求数组的第k小的数。
  方法是将两个数组a[m], b[n].
  分别求第k/2小的数
  如果a[k/2]=b[k/2], 则第k小的数为该数。
  如果a[k/2]<b[k/2], 那么a[1-k/2]都不会为第k小的数。
  如果a[k/2]>b[k/2], 那么b[1-k/2]都不会为第k小的数。
*/


class Solution 
{
        public:
    	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    	{
            int m = nums1.size(), n = nums2.size();
            if((m+n) % 2 != 0)
                return find(nums1, nums2, 0, m-1, 0, n-1, (m+n)/2+1);
            else
            {
            	double r1 = find(nums1, nums2, 0, m-1, 0, n-1, (m+n)/2);
            	double r2 = find(nums1, nums2, 0, m-1, 0, n-1, (m+n)/2+1);
            	return (r1+r2)/2;
            }	
    	}

    	double find(vector<int>& n1, vector<int>& n2, int b1, int e1, int b2, int e2, int k)
    	{
    		if(e1-b1 > e2-b2)
    			return find(n2, n1, b2, e2, b1, e1, k);
    		else if(b1 > e1)
    			return n2[b2+k-1];
    		else if(k == 1)
    			return min(n1[b1], n2[b2]);
    		else
    		{
    			int o1 = min(k/2, e1-b1+1);
    			int o2 = k-o1;
    			if(n1[b1+o1-1] == n2[b2+o2-1])
    				return n1[b1+o1-1];
    			else if(n1[b1+o1-1] < n2[b2+o2-1])
    				return find(n1,n2,b1+o1,e1,b2,e2,k-o1);
    			else
    				return find(n1,n2,b1,e1,b2+o2,e2,k-o2);
    		}
    	}
};

