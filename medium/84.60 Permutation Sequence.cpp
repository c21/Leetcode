/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution 
{

	public:

	int num[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
	string getPermutation(int n, int k) 
	{
		int flag[10];
		memset(flag, 0, sizeof(flag));
		
		string s = "";	
		int x = n-1;
		while(k > 0)
		{
			if(k % num[x] == 0)
			{
				int q = k / num[x];
				int count = 0;
				for(int i = 1; i <= n; i++)
                                {
                                        if(flag[i] == 0)
                                        {
                                                count++;
                                                if(count == q)
                                                {
                                                        flag[i] = 1;
                                                        s += i + '0';
                                                        break;
                                                }
                                        }
                                }
				for(int i = n; i >= 1; i--)
				{
					if(flag[i] == 0)
						s += i+'0';
				}
				return s;
			}
			else
			{	
				int q = k / num[x];
				int r = k % num[x];
				int count = 0;
				for(int i = 1; i <= n; i++)
				{
					if(flag[i] == 0)
					{
						count++;
						if(count == q+1)
						{
							flag[i] = 1;
							s += i + '0';
							x--;
							k = r;
							break;
						}
					}
				}
			}	
		}		
		return s;	
	}

};

/*
  从最高位开始确定每一位。
*/
