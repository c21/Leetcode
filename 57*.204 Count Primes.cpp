/*
Description:

Count the number of prime numbers less than a non-negative number, n.
*/

#include <map>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

class Solution 
{

	public:

    	int countPrimes(int n) 
	{

		int count = 0;
/*		vector<int> record = vector<int>();
		for(int i = 0; i < n; i++)
			record.push_back(0);	
*/
		int* record = (int*)malloc(sizeof(int)*n);
//		memset(record, 0, sizeof(record));		
		for(int i = 0; i < n; i++)
			record[i] = 0;
		for(int i = 2; i*i <= n; i++)
		{
			if(record[i] == 0)
			{
				for(int j = 2; i*j < n; j++)
				{
					record[i*j] = 1;
				}	
			}	
		}		

		for(int i = 2; i < n; i++)
		{
			if(record[i] == 0)
				count++;
		}
		return count;
    	}

};

int main()
{
	Solution s;
	int n;
	while(scanf("%d", &n) == 1)
	{
		printf("%d\n", s.countPrimes(n));
	}		
	return 0;
}


/*
  明确题目可以使用找素数的筛法。
  一开始觉得n很大，用数组记录空间会不够，就使用map, 结果超时。
  后来发现答案使用数组，于是开vector, 空间不够，后来改用malloc.
  如果以后题目有可能要开很大数组，用malloc比用STL好。
*/
