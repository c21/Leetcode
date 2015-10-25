/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.


*/

#include <vector>
#include <cstdio>

using namespace std;

class Solution 
{

	public:

	int num = 0;

	int totalNQueens(int n) 
	{
		num = 0;
		if(n == 0)
			return 0;
		else
		{
			vector<int> record = vector<int>();
			for(int i = 0; i < n; i++)
				record.push_back(0);
			count(0, n, record);
			return num;	
		}
	}

	void count(int k, int n, vector<int>& record)
	{
		if(k == n)
		{
			num++;
		}	
		else
		{
			for(int i = 0; i < n; i++)
			{
				int x = k;
				int y = i;
				int no_flag = 0;
				for(int j = 0; j < k; j++)
				{
					int x1 = j;
					int y1 = record[j];
					if(y1 == y || x-x1 == y-y1 || x-x1 == y1-y)
					{
						no_flag = 1;
						break;
					}
				}			
				if(no_flag == 0)
				{
					record[k] = i;
					count(k+1, n, record);	
				}
			}
				
		}	
	}
};

int main()
{
	Solution s;
	int n;
	while(scanf("%d", &n) == 1)
	{
		printf("%d\n", s.totalNQueens(n));	
	}	
	return 0;
}

/*
  枚举。
*/
