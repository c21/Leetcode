/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/

#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

class Solution 
{

	public:

	vector<vector<int> > result;


	vector<vector<int> > combinationSum3(int k, int n) 
	{
		result = vector<vector<int> >();
						
		int array[11];
		memset(array, 0, sizeof(array));

		gen_sum(0, k, n, 0, array, 1);

		return result;	
	}

	void gen_sum(int now_k, int k, int sum, int now_sum, int* array, int now_p)
	{
		if(k == 1)
		{
			if(sum >= 1 && sum <= 9)
			{
				vector<int> r = vector<int>();
				r.push_back(sum);
				result.push_back(r);
			}
		}
		else if(now_k == k-1)
		{
			if(sum-now_sum > array[now_k-1] && sum-now_sum <= 9)
			{
				vector<int> r = vector<int>();
				for(int i = 0; i < now_k; i++)
					r.push_back(array[i]);
				r.push_back(sum-now_sum);
				result.push_back(r);			
			}
		}
		else 
		{
			if(now_sum + now_p < sum)
			{
				if(k-now_k == 9-now_p+1)
				{
					if(now_sum + (9+now_p)*(9-now_p+1)/2 == sum)
					{
						vector<int> r = vector<int>();
                                		for(int i = 0; i < now_k; i++)
                                        		r.push_back(array[i]);
						for(int i = now_p; i <= 9; i++)
							r.push_back(i);
						result.push_back(r);
					}
				}
				else if(k-now_k < 9-now_p+1)
				{
	
					array[now_k] = now_p;
					now_sum += now_p;
					now_k++;
					now_p++;
				
					gen_sum(now_k, k, sum, now_sum, array, now_p);

					now_k--;
					now_sum -= array[now_k];
				
					gen_sum(now_k, k, sum, now_sum, array, now_p);
				}
			}		
		}
	}
		
};


int main()
{
	Solution s;
	int k, n;
	while(scanf("%d %d", &k, &n) == 2)
	{
		vector<vector<int> > r = s.combinationSum3(k, n);

		for(int i = 0; i < r.size(); i++)
		{
			for(int j = 0; j < r[i].size(); j++)
				printf("%d ", r[i][j]);
			printf("\n");
		}
	}
	
	return 0;
}

/*
  求组合，中间不可能的情况可以剪枝：剩余的x-9比剩余的和小，剩下一个数不用遍历。
*/
