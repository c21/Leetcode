/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

class Solution 
{

	public:

    	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
	{
		vector<int> ans = vector<int>();

    		int p1 = 0;
		int p2 = 0;
		while(p1 < m && p2 < n)
		{
			if(nums1[p1] <= nums2[p2])
			{
				ans.push_back(nums1[p1]);
				p1++;
			}	
			else
			{
				ans.push_back(nums2[p2]);
				p2++;
			}
			
		}

		if(p1 < m)
		{
			while(p1 < m)
			{
				ans.push_back(nums1[p1]);
				p1++;
			}
		}
		else if(p2 < n)
		{
			while(p2 < n)
                        {       
                                ans.push_back(nums2[p2]);
                                p2++;
                        }
		}

		for(int i = 0; i < ans.size(); i++)
			nums1[i] = ans[i];
	}

};

/*
  模拟
*/
