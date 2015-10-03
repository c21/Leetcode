/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

class Solution 
{

	public:

	vector<int> record;
		
    	int numTrees(int n) 
	{/*
		record = (int*)malloc(sizeof(int)*(n+1));
		memset(record, 0, sizeof(record));
	*/
		record = vector<int>();
		for(int i = 0; i <= n; i++)
			record.push_back(0);
		return get_num(n);
    	}

	int get_num(int n)
	{
		if(record[n] != 0)
			return record[n];
		else
		{
			if(n == 0)
			{
				record[n] = 0;
                        	return 0;
			}
                	else if(n == 1)
			{
				record[n] = 1;
                        	return 1;
			}
                	else if(n > 1)
                	{
                        	int sum = 0;
                        	for(int i = 1; i <= n; i++)
                        	{
                                	if(i == 1 || i == n)
                                        	sum += get_num(n-1);
                                	else
                                        	sum += get_num(i-1)*get_num(n-i);
                        	}
				record[n] = sum;
                        	return sum;
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
		printf("%d\n", s.numTrees(n));
	}
	return 0;
}

/*
  设f(n)为存储1-n的二叉搜索树数目
  f(n) = 2f(n-1) + sum(i=2;i<=n-1;i++) f(i-1)*f(n-i)
  一开始超时，后来算出中间结果f(i)保存在record里以后通过。
*/
