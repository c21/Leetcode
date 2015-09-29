/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

#include <vector>
#include <cstdio>

using namespace std;

class Solution 
{

	public:

    	vector<int> getRow(int rowIndex) 
	{
		vector<int> result = vector<int>();

		result.push_back(1);

		for(int i = 1; i <= rowIndex; i++)
		{
			long long x = result[i-1];
			x = x*(rowIndex-i+1);
			x = x / i;
			result.push_back(x);	
		}			

		return result;
    	}

};

int main()
{
	Solution s;
	int n;
	while(scanf("%d", &n) == 1)
	{
		vector<int> r = s.getRow(n);
		for(int i = 0; i < r.size(); i++)
			printf("%d ", r[i]);
		printf("\n");
	}	
	return 0;
}

/*
  利用递推公式C(n,k) = C(n,k-1)*(n-k+1)/k即可。
  第一次交是wrong answer, 发现在做乘法时有可能会溢出，改为long long. 以后需要注意溢出。
*/
