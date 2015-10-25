/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution 
{

	public:

	vector<vector<string> > solveNQueens(int n) 
	{
		vector<vector<string> > result = vector<vector<string> >();
		if(n == 0)
			return result;

		vector<int> flag = vector<int>();
		for(int i = 0; i < n; i++)
			flag.push_back(-1);
		solve(0, flag, result);
		return result;			
	}

	void solve(int k, vector<int>& flag, vector<vector<string> >& result)	
	{
		if(k == flag.size())
		{
			vector<string> r = vector<string>();
			for(int i = 0; i < k; i++)
			{
				string s = "";
				for(int j = 0; j < k; j++)
				{
					if(j == flag[i])
						s += "Q";
					else
						s += ".";	
				}
				r.push_back(s);	
			}	
			result.push_back(r);
		}
		else
		{
			for(int i = 0; i < flag.size(); i++)
			{
				int x = k;
				int y = i;
				int no_flag = 0;
				for(int j = 0; j < k; j++)
				{
					int x1 = j;
					int y1 = flag[j];
					if(y1 == y || x-x1 == y-y1 || x-x1 == y1-y)
					{
						no_flag = 1;
						break;
					}
				}	
				if(no_flag == 0)
				{
					flag[k] = i;
					solve(k+1, flag, result);			
				}		
			}	
		}	
	}	
};

int main()
{
	Solution s;
	int n;
	while(cin >> n)
	{
		vector<vector<string> > r = s.solveNQueens(n);
		for(int i = 0; i < r.size(); i++)
		{
			for(int j = 0; j < r[i].size(); j++)
				cout << r[i][j] << endl;

			cout << endl;
		}	
	}	
	return 0;	
}

/*
  枚举。
*/
